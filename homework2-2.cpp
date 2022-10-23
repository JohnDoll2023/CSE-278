// Copyright 2020 John Doll
#include <iostream>
#include <map>
#include <string>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

using Grades = map<string, vector<double> >;
Grades parsedIn = {{"final_exam", {0, 0}}, {"homework", {0, 0}},
                  {"lab", {0, 0}}, {"midterm", {0, 0}},
                  {"quiz", {0, 0}}};
Grades scores = {{"final_exam", {0}}, {"homework", {0}}, {"lab", {0}},
                  {"midterm", {0}}, {"quiz", {0}}};

void parseInputFile(ifstream& in) {
  string input = "";
  vector<string> contents;
  while (getline(in, input)) {
    boost::split(contents, input, boost::is_any_of(","));
    if (parsedIn.find(contents[0]) == parsedIn.end()) {
      vector<double> temp = {stod(contents[1]), stod(contents[2])};
      parsedIn[contents[0]] = temp;
    } else {
      vector<double> current = parsedIn[contents[0]];
      double one = current[0] + stod(contents[1]);
      double two = current[1] + stod(contents[2]);
      parsedIn[contents[0]] = {one, two};
    }
  }
}

void calculate() {
  for (auto& grade : parsedIn) {
    vector<double> values = grade.second;
    scores[grade.first] = {(values[0]/values[1])*100};
  }
}

void convertToLetter(map<string, string>& lG) {
  for (auto& grade : scores) {
    vector<double> values = grade.second;
    if (values[0] >= 97) lG[grade.first] = "A+";
    else if (values[0] >= 93) lG[grade.first] = "A";
    else if (values[0] >= 90) lG[grade.first] = "A-";
    else if (values[0] >= 87) lG[grade.first] = "B+";
    else if (values[0] >= 83) lG[grade.first] = "B";
    else if (values[0] >= 80) lG[grade.first] = "B-";
    else if (values[0] >= 77) lG[grade.first] = "C+";
    else if (values[0] >= 73) lG[grade.first] = "C";
    else if (values[0] >= 70) lG[grade.first] = "C-";
    else if (values[0] >= 67) lG[grade.first] = "D+";
    else if (values[0] >= 63) lG[grade.first] = "D";
    else if (values[0] >= 60) lG[grade.first] = "D-";
    else
      lG[grade.first] = "F";
  }
}

void parseWeights(istream& in, map<string, double>& weights) {
  string input = "";
  vector<string> contents;
  while (getline(in, input)) {
    boost::split(contents, input, boost::is_any_of(","));
    weights[contents[0]] = stod(contents[1]);
  }
}

void calcFinal(map<string, double> w, map<string, string>& cF) {
  double total = (w["final_exam"] * scores["final_exam"][0]) +
                 (w["homework"] * scores["homework"][0]) +
                 (w["lab"] * scores["lab"][0]) + (w["midterm"] *
                 scores["midterm"][0]) +
                 (w["quiz"] * scores["quiz"][0]);
  if (total >= 97) cF["course"] = "A+";
  else if (total >= 93) cF["course"] = "A";
  else if (total >= 90) cF["course"] = "A-";
  else if (total >= 87) cF["course"] = "B+";
  else if (total >= 83) cF["course"] = "B";
  else if (total >= 80) cF["course"] = "B-";
  else if (total >= 77) cF["course"] = "C+";
  else if (total >= 73) cF["course"] = "C";
  else if (total >= 70) cF["course"] = "C-";
  else if (total >= 67) cF["course"] = "D+";
  else if (total >= 63) cF["course"] = "D";
  else if (total >= 60) cF["course"] = "D-";
  else
    cF["course"] = "F";
  scores.insert({"course", {total}});
}

void p(ostream& out, map<string, string> lG, map<string, string> cF) {
  out << fixed << showpoint;
  out << setprecision(2);
  out << "final_exam: " << scores["final_exam"][0] <<
         "% (" << lG["final_exam"] << ")" << endl;
  out << "homework: " << scores["homework"][0] <<
         "% (" << lG["homework"] << ")" << endl;
  out << "lab: " << scores["lab"][0] << "% (" <<
         lG["lab"] << ")" << endl;
  out << "midterm: " << scores["midterm"][0] <<
         "% (" << lG["midterm"] << ")" << endl;
  out << "quiz: " << scores["quiz"][0] << "% (" <<
         lG["quiz"] << ")" << endl;
  out << "Course Grade: " << scores["course"][0] <<
         "% (" << cF["course"] << ")" << endl;
}

int main(int argc, char** argv) {
  if (argc != 3 && argc != 4) {
    cerr << "Need to specify necessary files" << endl;
    return 0;
  }
  ifstream inFile(argv[1]); ofstream outFile(argv[2]);
  if (!inFile.good() || !outFile.good()) {
    cerr << "There was an error opening one of the files" << endl;
    return 0;
  }
  parseInputFile(inFile); calculate();
  map<string, string> letterGrade; convertToLetter(letterGrade);
  map<string, double> weights = {{"final_exam", .25}, {"homework", .35},
                                {"lab", .1}, {"midterm", .2}, {"quiz", .1}};
  if (argc == 4) {
    ifstream in(argv[3]);
    if (!in.good()) {
      cerr << "There was an error opening one of the files" << endl;
      return 0;
    }
    parseWeights(in, weights);
  }
  map<string, string> courseFinal;
  calcFinal(weights, courseFinal);
  p(outFile, letterGrade, courseFinal); p(cout, letterGrade, courseFinal);
}

