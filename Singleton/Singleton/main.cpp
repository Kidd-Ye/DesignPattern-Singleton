//
//  main.cpp
//  Singleton
//
//  Created by kidd on 2018/6/19.
//  Copyright © 2018年 Kidd. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

//懒汉(线程不安全)：两个线程同时首次调用instance方法且同时检测到p是NULL值，则两个线程会同时构造一个实例给p
class singleton
{
protected:
    singleton(){}
private:
    static singleton* p;
public:
    static singleton* instance();
};

singleton* singleton::p = NULL;
singleton* singleton::instance()
{
    if (p == NULL){
        cout<< "创建单例" <<endl;
        p = new singleton();
    }else{
        cout<< "单例已创建" <<endl;
    }
    return p;
}

/*
// 饿汉(线程安全)
class singleton
{
 
protected:
    singleton(){}
 
private:
    static singleton* p;
 
public:
    static singleton* initance();
};
 
singleton* singleton::p = new singleton;
singleton* singleton::initance()
{
    return p;
}
 */

int main(int argc, const char * argv[]) {
    // insert code here...
    cout<< "main" <<endl;
    singleton* s1 = singleton::instance();
    singleton* s2 = singleton::instance();
    
    if (s1 == s2) {
        cout<< "s1 == s2" <<endl;
    }else{
        cout<< "s1 != s2" <<endl;
    }
    
    return 0;
}
