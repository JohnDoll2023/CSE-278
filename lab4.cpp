// Copyright John Doll
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

using StrIntMap = unordered_map<string, int>;
StrIntMap monthMap;
StrIntMap weekMap;
bool monthWrong;
bool dayWrong;

void createWeekMap(StrIntMap& weekMap) {
  // Create an unordered map of the days of the week to integers
  // Sunday should be one, etc.  Make sure to capitalize the names of the
  // days.
  weekMap = {{"Sunday", 1}, {"Monday", 2}, {"Tuesday", 3}, {"Wednesday", 4},
            {"Thursday", 5}, {"Friday", 6}, {"Saturday", 7}};
}

void createMonthMap(StrIntMap& monthMap) {
  // Create an unordered map of the months of the year to integers
  // January should be zero, etc.  Make sure to capitalize the names of the
  // Months.
  monthMap = {{"January", 1}, {"February", 2}, {"March", 3}, {"April", 4},
             {"May", 5},  {"June", 6}, {"July", 7}, {"August", 8},
             {"September", 9}, {"October", 10}, {"November", 11},
             {"December", 12}};
}

bool has(const StrIntMap& map, string str) {
  if (map.find(str) != map.end())
    return true;
  return false;
}

int main() {
  createWeekMap(weekMap);
  createMonthMap(monthMap);
  string month, day, wrongMonth, wrongDay;
  while (!has(monthMap, month) || !has(weekMap, day)) {
    cout << "Enter a month and weekday: ";
    getline(cin, day);
    month = day.substr(0, day.find(" ", 0));
    day.erase(0, month.size() + 1);
    if (!has(monthMap, month)) {
      monthWrong = true;
      wrongMonth = month;
    } else if (!has(weekMap, day)) {
      dayWrong = true;
      wrongDay = day;
    }
  }
  cout << month << ", " << day << " => " << monthMap[month] << ", ";
  cout  <<  weekMap[day] << endl;
  if (monthWrong) cout << "The month " << wrongMonth << " is not valid" << endl;
  if (dayWrong) cout << "The day " << wrongDay << " is not valid" << endl;
  return 0;
}

