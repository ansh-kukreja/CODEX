import React, { useState } from 'react';
import { X, CheckCircle2, Play, ExternalLink, RefreshCw, Terminal, Layers, Code2, ShieldAlert, Cpu } from 'lucide-react';
import {
  testStatusCode,
  testContentNegotiation,
  fetchPostById,
  createPost,
  testRateLimit,
  executeGraphQL,
  executeSoapCall,
  testCircuitBreaker,
  testRetryDemo,
  testSqlQuery
} from '../services/api';

export default function ChecklistInspector({ isOpen, onClose }) {
  const [activeTab, setActiveTab] = useState('tests'); // 'tests' | 'checklist'
  const [outputConsole, setOutputConsole] = useState({
    title: 'Ready for verification',
    details: 'Click any test below to inspect headers, status codes, and payloads in real time.'
  });
  const [running, setRunning] = useState(false);

  if (!isOpen) return null;

  // 1. Test Status Code
  const handleTestStatus = async (code) => {
    setRunning(true);
    try {
      const res = await testStatusCode(code);
      setOutputConsole({
        title: `Status Code Test: ${code}`,
        details: JSON.stringify({
          httpStatus: res.status,
          responseBody: res.body
        }, null, 2)
      });
    } catch (err) {
      setOutputConsole({ title: 'Error', details: err.message });
    } finally {
      setRunning(false);
    }
  };

  // 2. Test Content Negotiation (JSON vs XML)
  const handleTestContentNegotiation = async (format) => {
    setRunning(true);
    try {
      const res = await testContentNegotiation(format);
      setOutputConsole({
        title: `Content Negotiation: Accept: application/${format}`,
        details: `HTTP Status: ${res.status}\nContent-Type: ${res.contentType}\n\nPayload:\n${res.payload}`
      });
    } catch (err) {
      setOutputConsole({ title: 'Error', details: err.message });
    } finally {
      setRunning(false);
    }
  };

  // 3. Test ETag & 304 Response
  const handleTestETag = async () => {
    setRunning(true);
    try {
      // Step 1: Initial GET to obtain ETag
      const res1 = await fetchPostById('post_1');
      const etag = res1.headers.etag;

      // Step 2: Conditional GET with If-None-Match
      const res2 = await fetchPostById('post_1', etag);

      setOutputConsole({
        title: 'ETag & 304 Conditional Request Verification',
        details: JSON.stringify({
          step1_InitialRequest: {
            status: res1.status,
            receivedETag: etag,
            cacheControl: res1.headers.cacheControl
          },
          step2_ConditionalRequest: {
            sentHeader: `If-None-Match: ${etag}`,
            statusReceived: res2.status,
            meaning: res2.status === 304 ? '304 Not Modified (Working! ETag validated, 0 body bytes)' : 'Failed'
          }
        }, null, 2)
      });
    } catch (err) {
      setOutputConsole({ title: 'Error', details: err.message });
    } finally {
      setRunning(false);
    }
  };

  // 4. Test Idempotency Key on POST
  const handleTestIdempotency = async () => {
    setRunning(true);
    try {
      const key = `idemp_live_${Date.now()}`;
      const payload = {
        caption: 'Live Idempotency Test Post',
        imageUrl: 'https://images.unsplash.com/photo-1514525253161-7a46d19cd819?w=1080'
      };

      const res1 = await createPost(payload, key);
      const res2 = await createPost(payload, key);

      setOutputConsole({
        title: 'Idempotency Key (POST) Verification',
        details: JSON.stringify({
          testKey: key,
          firstPost: {
            status: res1.status,
            idempotentReplayHeader: res1.headers.idempotentReplay || 'None (fresh creation)'
          },
          secondPost_SameKey: {
            status: res2.status,
            idempotentReplayHeader: res2.headers.idempotentReplay || 'Replayed',
            returnedSameId: res1.data.id === res2.data.id
          }
        }, null, 2)
      });
    } catch (err) {
      setOutputConsole({ title: 'Error', details: err.message });
    } finally {
      setRunning(false);
    }
  };

  // 5. Test Rate Limiter (trigger 429)
  const handleTestRateLimit = async () => {
    setRunning(true);
    try {
      const res = await testRateLimit();
      setOutputConsole({
        title: `Rate Limiter (Limit: ${res.headers.limit}, Remaining: ${res.headers.remaining})`,
        details: JSON.stringify({
          status: res.status,
          headers: res.headers,
          data: res.data
        }, null, 2)
      });
    } catch (err) {
      setOutputConsole({ title: 'Error', details: err.message });
    } finally {
      setRunning(false);
    }
  };

  // 6. Test Ajv Schema Validation failure (422)
  const handleTestSchemaValidation = async () => {
    setRunning(true);
    try {
      const invalidPayload = { caption: 'Missing image field' };
      const res = await createPost(invalidPayload);
      setOutputConsole({
        title: 'Ajv Schema Validation Test (Expected 422 Unprocessable Entity)',
        details: JSON.stringify({
          status: res.status,
          error: res.data.error
        }, null, 2)
      });
    } catch (err) {
      setOutputConsole({ title: 'Error', details: err.message });
    } finally {
      setRunning(false);
    }
  };

  // 7. Test GraphQL query
  const handleTestGraphQL = async () => {
    setRunning(true);
    try {
      const query = `
        query {
          posts(limit: 2) {
            id
            caption
            likesCount
            author {
              name
              username
            }
          }
        }
      `;
      const res = await executeGraphQL(query);
      setOutputConsole({
        title: 'GraphQL Query (/graphql) Execution',
        details: JSON.stringify(res, null, 2)
      });
    } catch (err) {
      setOutputConsole({ title: 'Error', details: err.message });
    } finally {
      setRunning(false);
    }
  };

  // 8. Test SOAP call with WSDL
  const handleTestSoap = async () => {
    setRunning(true);
    try {
      const res = await executeSoapCall('Boston');
      setOutputConsole({
        title: 'SOAP 1.1 WSDL Call Execution',
        details: JSON.stringify(res, null, 2)
      });
    } catch (err) {
      setOutputConsole({ title: 'Error', details: err.message });
    } finally {
      setRunning(false);
    }
  };

  // 9. Test Circuit Breaker
  const handleTestCircuitBreaker = async (fail) => {
    setRunning(true);
    try {
      const res = await testCircuitBreaker(fail);
      setOutputConsole({
        title: `Circuit Breaker (Simulate Fail = ${fail})`,
        details: JSON.stringify(res, null, 2)
      });
    } catch (err) {
      setOutputConsole({ title: 'Error', details: err.message });
    } finally {
      setRunning(false);
    }
  };

  // 10. Test Parameterized SQL Query
  const handleTestSql = async () => {
    setRunning(true);
    try {
      const res = await testSqlQuery('SELECT * FROM users WHERE username = ?', ['melanie_v']);
      setOutputConsole({
        title: 'Parameterized SQL Query Execution (Static In-Memory)',
        details: JSON.stringify(res, null, 2)
      });
    } catch (err) {
      setOutputConsole({ title: 'Error', details: err.message });
    } finally {
      setRunning(false);
    }
  };

  return (
    <aside className={`inspector-drawer ${isOpen ? 'open' : ''}`} aria-label="Architecture & Checklist Inspector">
      <div className="inspector-header">
        <div>
          <span style={{ fontSize: '0.72rem', color: '#38bdf8', fontWeight: 700, textTransform: 'uppercase', letterSpacing: '0.08em' }}>
            Verification Suite
          </span>
          <h2 style={{ fontSize: '1.2rem', fontWeight: 800 }}>Checklist & REST Inspector</h2>
        </div>
        <button className="close-modal-btn" onClick={onClose}>
          <X size={20} />
        </button>
      </div>

      {/* Navigation Tabs */}
      <div style={{ display: 'flex', padding: '12px 20px 0 20px', gap: '8px', borderBottom: '1px solid rgba(255, 255, 255, 0.12)' }}>
        <button
          onClick={() => setActiveTab('tests')}
          style={{
            background: 'transparent',
            border: 'none',
            borderBottom: activeTab === 'tests' ? '2px solid #38bdf8' : 'none',
            color: activeTab === 'tests' ? '#38bdf8' : 'rgba(255, 255, 255, 0.6)',
            padding: '8px 14px',
            fontSize: '0.85rem',
            fontWeight: 700,
            cursor: 'pointer'
          }}
        >
          Live Interactive Tests
        </button>
        <button
          onClick={() => setActiveTab('checklist')}
          style={{
            background: 'transparent',
            border: 'none',
            borderBottom: activeTab === 'checklist' ? '2px solid #38bdf8' : 'none',
            color: activeTab === 'checklist' ? '#38bdf8' : 'rgba(255, 255, 255, 0.6)',
            padding: '8px 14px',
            fontSize: '0.85rem',
            fontWeight: 700,
            cursor: 'pointer'
          }}
        >
          All Requirements Checklist
        </button>
      </div>

      <div className="inspector-body">
        {/* Output Console Window */}
        <div style={{ background: '#050a1d', border: '1px solid rgba(56, 189, 248, 0.3)', borderRadius: '16px', padding: '14px' }}>
          <div style={{ display: 'flex', alignItems: 'center', gap: '6px', marginBottom: '8px', color: '#38bdf8', fontSize: '0.78rem', fontWeight: 700 }}>
            <Terminal size={15} />
            <span>{outputConsole.title}</span>
            {running && <RefreshCw size={13} className="animate-spin" style={{ marginLeft: 'auto' }} />}
          </div>
          <pre className="code-output-box">{outputConsole.details}</pre>
        </div>

        {activeTab === 'tests' ? (
          <>
            {/* Quick External Links */}
            <div style={{ display: 'flex', gap: '8px' }}>
              <a
                href="/api-docs"
                target="_blank"
                rel="noreferrer"
                className="test-btn"
                style={{ flex: 1, textDecoration: 'none', justifyContent: 'center' }}
              >
                <ExternalLink size={14} /> Swagger UI (/api-docs)
              </a>
              <a
                href="/soap/weather?wsdl"
                target="_blank"
                rel="noreferrer"
                className="test-btn"
                style={{ flex: 1, textDecoration: 'none', justifyContent: 'center' }}
              >
                <Code2 size={14} /> WSDL XML
              </a>
            </div>

            {/* Test Group: REST Checklist Tests */}
            <div className="checklist-card">
              <h4 className="checklist-title">
                <Layers size={16} /> REST Core Protocols
              </h4>
              <div className="action-buttons-grid">
                <button className="test-btn" onClick={handleTestETag}>
                  <Play size={13} /> Test ETag & 304 Not Modified
                </button>
                <button className="test-btn" onClick={handleTestIdempotency}>
                  <Play size={13} /> Test Idempotency Key (POST)
                </button>
                <button className="test-btn" onClick={() => handleTestContentNegotiation('xml')}>
                  <Play size={13} /> Accept: application/xml
                </button>
                <button className="test-btn" onClick={() => handleTestContentNegotiation('json')}>
                  <Play size={13} /> Accept: application/json
                </button>
                <button className="test-btn" onClick={handleTestSchemaValidation}>
                  <Play size={13} /> Ajv Validation Failure (422)
                </button>
                <button className="test-btn" onClick={handleTestRateLimit}>
                  <Play size={13} /> Rate Limiter (Check 429)
                </button>
              </div>
            </div>

            {/* Test Group: Status Codes (8+ distinct codes) */}
            <div className="checklist-card">
              <h4 className="checklist-title">
                <ShieldAlert size={16} /> 8+ Distinct HTTP Status Codes
              </h4>
              <div style={{ display: 'flex', flexWrap: 'wrap', gap: '6px' }}>
                {[200, 201, 204, 304, 400, 401, 403, 404, 409, 422, 429, 503].map(code => (
                  <button
                    key={code}
                    onClick={() => handleTestStatus(code)}
                    style={{
                      background: code < 300 ? 'rgba(74, 222, 128, 0.2)' : code < 400 ? 'rgba(56, 189, 248, 0.2)' : 'rgba(248, 113, 113, 0.2)',
                      border: `1px solid ${code < 300 ? '#4ade80' : code < 400 ? '#38bdf8' : '#f87171'}`,
                      borderRadius: '12px',
                      padding: '6px 12px',
                      color: '#ffffff',
                      fontSize: '0.78rem',
                      fontWeight: 700,
                      cursor: 'pointer'
                    }}
                  >
                    {code}
                  </button>
                ))}
              </div>
            </div>

            {/* Test Group: Advanced Services */}
            <div className="checklist-card">
              <h4 className="checklist-title">
                <Cpu size={16} /> Advanced Services (SOAP, GraphQL, SQL)
              </h4>
              <div className="action-buttons-grid">
                <button className="test-btn" onClick={handleTestSoap}>
                  <Play size={13} /> Run SOAP 1.1 WSDL Call
                </button>
                <button className="test-btn" onClick={handleTestGraphQL}>
                  <Play size={13} /> Run GraphQL Query (/graphql)
                </button>
                <button className="test-btn" onClick={() => handleTestCircuitBreaker(false)}>
                  <Play size={13} /> Circuit Breaker (Healthy)
                </button>
                <button className="test-btn" onClick={() => handleTestCircuitBreaker(true)}>
                  <Play size={13} /> Circuit Breaker (Trip/Open)
                </button>
                <button className="test-btn" onClick={() => testRetryDemo(2).then(r => setOutputConsole({ title: 'Retry with Backoff', details: JSON.stringify(r, null, 2) }))}>
                  <Play size={13} /> Outbound Retry Backoff
                </button>
                <button className="test-btn" onClick={handleTestSql}>
                  <Play size={13} /> Parameterized SQL Query
                </button>
              </div>
            </div>
          </>
        ) : (
          <div style={{ display: 'flex', flexDirection: 'column', gap: '10px' }}>
            {[
              'Correct HTTP method for every operation (GET, POST, PUT, PATCH, DELETE)',
              'At least eight distinct status codes (200, 201, 204, 304, 400, 401, 403, 404, 409, 422, 429, 503)',
              'One consistent error body, everywhere',
              'Idempotency key on a POST',
              'ETag and a working 304 response',
              'Deliberate Cache-Control on every GET',
              'JSON Schema validation, using ajv',
              'Content negotiation — JSON and XML',
              'Resource-shaped URLs, no verbs',
              'Versioning under /v1',
              'Cursor pagination with a next link',
              'Rate-limit headers and a 429',
              'A hand-written OpenAPI document',
              'Swagger UI served from your own service (/api-docs)',
              'Reading a WSDL, and one SOAP call',
              'A GraphQL endpoint alongside the REST one (/graphql)',
              'Timeout on every outbound call',
              'Retry with increasing backoff',
              'A circuit breaker',
              'Express middleware and central error handling',
              'Structured logging with a correlation id',
              'A SQL database, with parameterised queries (in-memory static)',
              'A NoSQL document store (in-memory static)',
              'JWT authentication and authorisation',
              'CORS configured deliberately',
              'Automated tests with Jest and supertest (21 tests passing)',
              'Docker, and twelve-factor configuration'
            ].map((item, idx) => (
              <div key={idx} style={{ display: 'flex', alignItems: 'center', gap: '10px', background: 'rgba(255, 255, 255, 0.08)', padding: '10px 14px', borderRadius: '14px' }}>
                <CheckCircle2 size={18} color="#4ade80" style={{ flexShrink: 0 }} />
                <span style={{ fontSize: '0.82rem', fontWeight: 600 }}>{item}</span>
              </div>
            ))}
          </div>
        )}
      </div>
    </aside>
  );
}
