#include <iostream>
#include <array>
#include "student.h"
#include "roster.h"
#include "degree.h"

int main() {
    const std::string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Ian,Allen,ialle66@wgu.edu,38,18,23,29,SOFTWARE" };

    Roster * classRoster = new Roster();
    for (int i=0;i<=4;i++) {
        classRoster[i].populateStudentArray(studentData[i]);
    }


/*  std::cout << "studentData[] length is: " << studentData->size() << std::endl;
    for(int x=0;x<studentData->size();x++) {
    for(int x=0;x<=4;x++) {
    std::cout << studentData[x] << "[" << x << "] " << std::endl;
    }


    for(int a=1;a<=5;a++) {
        for(int b=1; b<=9; b++) {
            //int tempID = studentData[];
        }
    }
*/

}