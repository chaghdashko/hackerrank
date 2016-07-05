/*
 * main.cpp
 *
 *  Created on: 5 Tem 2016
 *      Author: cagdasko
 */

#include <iostream>
#include <vector>

using namespace std;

//
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \\|     |// '.
//                 / \\|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='
//
//
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main() {
	int n;
	cin >> n;

	int sum = 0;
	int sumMax = 0;

	vector<int> v;

	while (n != 0) {
		int rem = n % 2;
		n = n / 2;
		v.push_back(rem);
	}

	for (size_t i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	if (v.size() == 1)
		cout << ((v[0] == 1) ? 1 : 0) << endl;
	else {
		for (size_t i = 0; i < v.size(); i++) {
			if (v[i] == 0) {
				if (sum > 0) {
					if (sum > sumMax) {
						sumMax = sum;
					}

					sum = 0;
				}
			} else {
				sum = sum + 1;
			}
		}

		if (sum > sumMax)
			sumMax = sum;

		cout << sumMax << endl;
	}

	return 0;
}

