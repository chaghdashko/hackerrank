#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Attribute {
private:
	string name;
	string value;
public:
	Attribute(string __name, string __value) {
		name = __name;
		value = __value;
	}

	string getName() {
		return name;
	}

	string getValue() {
		return value;
	}
};

vector<Attribute> getAttributes(string str) {
	vector<Attribute> attributes;
	stringstream ss(str);
	string attr_str;

	while (ss.rdbuf()->in_avail()) {
		string name;
		string value;
		string eq_sign;

		for (size_t i = 0; i < 3; i++) {
			if (i == 0)
				ss >> name;
			else if (i == 1)
				ss >> eq_sign;
			else /* i == 2 */
				ss >> value;
		}

		value = value.substr(1, value.find_last_of("\"") - 1);

		Attribute attribute(name, value);
		attributes.push_back(attribute);
	}

	return attributes;
}

int main() {
	int n, q;
	cin >> n >> q;

	string s;
	getline(cin, s);

	vector<string> source_lines;
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		source_lines.push_back(s);
	}

	map<string, string> attr_map;
	string tag = "";
	int level = 0;

	for (size_t i = 0; i < source_lines.size(); ++i) {
		string line = source_lines[i];

		/* end tag, skip this, e.g. </tag1> */
		if (line.at(1) == '/') {
			int pos = tag.find_last_of(".");

			if (pos != -1)
				tag = tag.substr(0, pos);
			else
				tag = "";

			//cout << "TAG ENDED: " << tag << endl;

			if (level != 0)
				level--;
		} else {
			string line_tag = line.substr(1, line.find_first_of(">") - 1);
			size_t pos = line_tag.find_first_of(" ");
			string local_tag = line_tag.substr(0, pos);

			if (tag != "") {
				tag = tag + "." + local_tag;
			} else {
				tag = local_tag;
			}

			//cout << "TAG STARTED: " << tag << endl;

			if (pos != -1) { /* not empty tag */
				string line_attrs = line_tag.substr(pos + 1, line_tag.size());
				vector<Attribute> attributes = getAttributes(line_attrs);

				for (size_t i = 0; i < attributes.size(); ++i) {
					string name = tag + "~" + attributes[i].getName();
					attr_map[name] = attributes[i].getValue();
				}
			}
		}
	}

	vector<string> queries(q);
	for (int i = 0; i < q; i++) {
		getline(cin, s);
		queries[i] = s;
	}

	for (size_t i = 0; i < queries.size(); i++) {
		auto it = attr_map.find(queries[i]);

		if (it != attr_map.end()) {
			cout << it->second << endl;
		} else {
			cout << "Not Found!" << endl;
		}
	}
}