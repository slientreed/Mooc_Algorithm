//
//  Student.h
//  Algorithm Learning
//
//  Created by mark on 2018/11/8.
//  Copyright © 2018年 mark. All rights reserved.
//

#ifndef Student_h
#define Student_h

#include <iostream>
#include<string>

using namespace std;

struct Student {
    string name;
    int score;
    
    bool operator<(const Student &otherStudent){     //运算符的重载，如果Student.score小，则Student小
    
        return score < otherStudent.score;
    }
    
    friend ostream& operator<<(ostream &os,const Student &student){  //对<<运算符重载；
    
        os<<"Student: "<<student.name<<" "<<student.score<<endl;
        return os;
    }
};

#endif /* Student_h */
