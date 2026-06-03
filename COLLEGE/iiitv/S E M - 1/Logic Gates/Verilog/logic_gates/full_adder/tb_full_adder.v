`timescale 1ns/1ps

module full_adder_tb;

reg a, b, cin;
wire sum, cout;

// Instantiate the DUT (Device Under Test)
full_adder uut (
    .a(a),
    .b(b),
    .cin(cin),
    .sum(sum),
    .cout(cout)
);

initial begin
    $display("a b cin | sum cout");
    $display("--------------------");

    // Test case 0
    a = 0; b = 0; cin = 0; #10;
    $display("%b %b  %b  |  %b    %b", a, b, cin, sum, cout);

    // Test case 1
    a = 0; b = 0; cin = 1; #10;
    $display("%b %b  %b  |  %b    %b", a, b, cin, sum, cout);

    // Test case 2
    a = 0; b = 1; cin = 0; #10;
    $display("%b %b  %b  |  %b    %b", a, b, cin, sum, cout);

    // Test case 3
    a = 0; b = 1; cin = 1; #10;
    $display("%b %b  %b  |  %b    %b", a, b, cin, sum, cout);

    // Test case 4
    a = 1; b = 0; cin = 0; #10;
    $display("%b %b  %b  |  %b    %b", a, b, cin, sum, cout);

    // Test case 5
    a = 1; b = 0; cin = 1; #10;
    $display("%b %b  %b  |  %b    %b", a, b, cin, sum, cout);

    // Test case 6
    a = 1; b = 1; cin = 0; #10;
    $display("%b %b  %b  |  %b    %b", a, b, cin, sum, cout);

    // Test case 7
    a = 1; b = 1; cin = 1; #10;
    $display("%b %b  %b  |  %b    %b", a, b, cin, sum, cout);

    $stop;
end

endmodule
