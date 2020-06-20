#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <utility>
#include <queue>
#include <vector>
using namespace std;

double exp_rand(double rate){
  double u;
  do{
    u = rand()/static_cast<double>(RAND_MAX);
  }
  while (u == 0.0 || u == 1.0);
  return -log(u)/rate;
}

typedef pair<double, double> Student;
double average_waiting_time(double arrival_rate, double service_rate, std::size_t number_of_students){
  queue<Student> studentsWaiting;
  double totalWaitingTime = 0;

  for(int i=0;i<number_of_students;i++){
    double arrivalTime = exp_rand(arrival_rate);
    double meetingTime = exp_rand(service_rate);
    Student nextInLine;
    nextInLine.first = meetingTime;
    nextInLine.second = arrivalTime;
    studentsWaiting.push(nextInLine);
  }
  Student firstStudent = studentsWaiting.front();
  studentsWaiting.pop();
  double meetTime_prevStudent = firstStudent.second;
  double waitTime_prevStudent = 0;
  for(int j=0;j<number_of_students-1;j++){
    Student currentStudent = studentsWaiting.front();
    studentsWaiting.pop();
    double avgTime_currentStudent = currentStudent.first;
    double waitTime_currentStudent = (waitTime_prevStudent + meetTime_prevStudent) - avgTime_currentStudent;
    if(waitTime_currentStudent > 0){
      totalWaitingTime += waitTime_currentStudent;
      waitTime_prevStudent = waitTime_currentStudent;
    } else {
      waitTime_prevStudent = 0;
    }
    meetTime_prevStudent = currentStudent.second;
  }
  return totalWaitingTime/number_of_students;
}

int main()
{
srand(time(0));
const std::size_t N(1000000);
cout << average_waiting_time(1.0, 5.0, N) << endl;
cout << average_waiting_time(1.0, 3.0, N) << endl;
cout << average_waiting_time(1.0, 2.0, N) << endl;
cout << average_waiting_time(1.0, 1.5, N) << endl;
cout << average_waiting_time(1.0, 1.1, N) << endl;
cout << average_waiting_time(1.0, 1.05, N) << endl;
cout << average_waiting_time(1.0, 1.025, N) << endl;
return 0;
}
