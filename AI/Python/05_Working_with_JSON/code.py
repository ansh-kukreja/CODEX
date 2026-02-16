import json

json_str = '{"name": "Ansh", "isDeveloper": true, "address": {"city": "Kurukshetra","state": "Haryana"}, "subjects": ["Python", "JavaScript", "C++", "C", "Java"]}'

py_obj = json.loads(json_str)  # "loads" stands for load string

json_str = json.dumps(py_obj)  # "dumps" stands for dump string




with open("05_Working_with_JSON/data.json", "r") as f:
    py_ob = json.load(f)    # "load" to work with files

    json.dump(py_ob, f, indent=4)     # "dump" to work with files