import json5
import sys

def convert(json_data):
    toml_snippets = []
    for name, snippet in json_data.items():
        body = "\n".join(snippet["body"])
        toml_snippets.append(f'''[[snippets]]
prefix = "{snippet["prefix"]}"
body = """{body}"""
''')
    return "\n".join(toml_snippets)

if __name__ == "__main__":
    input_file = sys.argv[1] if len(sys.argv) > 1 else 'snippets.json'
    with open(input_file) as f:
        data = json5.load(f)
    toml = convert(data)
    print(toml)
