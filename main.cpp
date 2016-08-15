//
//  main.cpp
//  application2
//
//  Created by Xiaohan Zhang on 16/7/29.
//  Copyright © 2016年 Xiaohan Zhang. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

struct data{
    string name;
    string team;
    double month_remain=0;
    double data1=0;
    double data2=0;
    double outside_credit=0;
    double channel_credit=0;
    
};

struct team{
    string team;
    double month_remain=0;
    double data1=0;
    double data2=0;
    double outside_credit=0;
    double channel_credit=0;
};

int main() {
    string target;
    cout<<"target file path:";
    cin>>target;
    ifstream fin(target);
    if(fin.fail()){
        cout<<"open file error"<<endl;
        return 0;
    }
    string s, Branchname, compname, money,temp;
    //int amount=0;
    vector<string> tmp;
    vector<data> all_data;
    vector<string> team_name;
    string value;
    int num_replace_comp;
    while(getline(fin,value))
    {
        istringstream iss(value);
        while(getline(iss,temp,',')){
            cout<<temp<<"  ";
            tmp.push_back(temp);
        }
        data temp_data;
        temp_data.name=tmp[0];
        temp_data.team=tmp[1];
        temp_data.month_remain=stod(tmp[2]);
        temp_data.data1=stod(tmp[3]);
        temp_data.data2=stod(tmp[4]);
        temp_data.outside_credit=stod(tmp[5]);
        temp_data.channel_credit=stod(tmp[6]);
        all_data.push_back(temp_data);
        vector<string>::iterator it;
        it=find(team_name.begin(),team_name.end(),tmp[1]);
        if (it==team_name.end())
        {
            team_name.push_back(tmp[1]);
        }
        tmp.clear();
    }
    vector<team> team_data;
    for(int i=0;i<team_name.size();i++){
        team tempo_team_data;
        tempo_team_data.team=team_name[i];
        team_data.push_back(tempo_team_data);
    }
    
    for(int k=0;k<all_data.size();k++){
        for(int j=0;j<team_data.size();j++){
            if(team_data[j].team==all_data[k].team){
                team_data[j].month_remain += all_data[k].month_remain;
                team_data[j].data1 += all_data[k].data1;
                team_data[j].data2 += all_data[k].data2;
                team_data[j].outside_credit += all_data[k].outside_credit;
                team_data[j].channel_credit += all_data[k].channel_credit;
            }
        }
    }
    string output;
    cout<<"output file path:";
    cin>>output;
    
    ofstream fou(output);
    fou.setf(ios::fixed);
    fou.precision(6);
    for(int h=0;h<team_data.size();h++){
        fou<<team_data[h].team<<","<<team_data[h].month_remain<<","<<team_data[h].data1<<","<<team_data[h].data2<<",";
        fou<<team_data[h].outside_credit<<","<<team_data[h].channel_credit<<",,"<<endl;
    }
    fin.close();
    fou.close();
    
}
