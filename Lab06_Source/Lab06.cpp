// Christina Gerstner
// clgdtf@mail.umkc.edu
// 9/24/2019
// CS201L Lab 06

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

double get_distance(double x1, double x2, double y1, double y2, double z1, double z2) { // calculates & returns distance to vector
	double total_distance = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2) + pow((z1 - z2), 2));
	return total_distance;
}

void sort_distance(vector<double>& distances) { // sorting vector w/o using sort()
	double min;
	for (int i = 0; i < distances.size(); i++) {
		min = i;
		for (int j = i + 1; j < distances.size(); j++) {
			if (distances.at(j) < distances.at(min)) {
				min = j;
			}
		}
		double temp_min = distances.at(min);
		distances.at(min) = distances.at(i);
		distances.at(i) = temp_min;
	}
}

int main() {

	double x1, x2, y1, y2, z1, z2; // values for formula
	vector<double> distances;

	ifstream fin("input.txt");
	ofstream fout("output.txt");
	ofstream fout_sorted("output_sorted.txt");

	while (fin.good()) {
		fin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
		distances.push_back(get_distance(x1, x2, y1, y2, z1, z2)); // calculates distance & adding to vector
	}

	for (int i = 0; i < distances.size(); i++) { // writes values to output.txt
		fout << distances.at(i) << endl;
	}

	sort_distance(distances); // sorts existing values from output file

	for (int i = 0; i < distances.size(); i++) { // writes values to output_sorted.txt
		fout_sorted << distances.at(i) << endl;
	}

	return 0;
}