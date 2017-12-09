#include <iostream>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>


using namespace std;
namespace w8 {
	template<class T>
	class DataTable {
	private:
		vector<T> x, y;
		int wmanip, dmanip;
	public:
		DataTable(ifstream& fs, int width, int decimals) : wmanip(width), dmanip(decimals) {
			//read file
			 //stream to use
			while (!fs.fail()) {
				string line;
				stringstream ss;
				getline(fs, line);
				if (!line.empty()) {
					T xx, yy;
					ss.str(line); // copy line to stringstream
					ss >> xx >> yy; // stream values to temp
					x.push_back(xx);
					y.push_back(yy);
				}
			}
			for (auto &i : y) {
				cout << i << ' ';
			}
		}
		T mean() const {
			T total = accumulate(y.begin(), y.end(), 0.0);
			return (total / y.size());
		}
		T sigma() const {
			T mv = mean(), SD = 0.0;
			for (int i = 0; i < y.size(); ++i)
				SD += (y[i] - mv) * (y[i] - mv);
			return sqrt(SD / (y.size() - 1));
		}
		T median() const {
			vector<T> temp = y;
			sort(temp.begin(), temp.end());
			T median = temp[temp.size() / 2];
			return median;
		}
		void regression(T& slope, T& y_intercept) const {
			auto n = x.size();
			auto s_x = accumulate(x.begin(), x.end(), 0.0);
			auto s_y = accumulate(y.begin(), y.end(), 0.0);
			auto s_xx = inner_product(x.begin(), x.end(), x.begin(), 0.0);
			auto s_xy = inner_product(x.begin(), x.end(), y.begin(), 0.0);
			slope = (n * s_xy - s_x * s_y) / (n * s_xx - s_x * s_x);
			y_intercept = (s_y - slope * s_x) / x.size();
		}
		void display(ostream& os) {
			os << setw(wmanip) << 'x' << setw(wmanip) << 'y' << endl;
			for (size_t i = 0; i < x.size(); i++) {
				os << setw(wmanip) << fixed << setprecision(dmanip) << x[i] <<
					setw(wmanip) << fixed << setprecision(dmanip) << y[i] << endl;
			}
		}
	};

	template<class T>
	ostream& operator<<(ostream& os, DataTable<T>& table) {
		table.display(os);
		return os;
	}
}
