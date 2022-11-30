#include <iostream>
#include <vector>
#include <random>
#include <string>

//using namespace std
using namespace std;

#pragma once
/**
 * Public : split
 * Description: Splits a string into parts 
 * Params:
 *string s
 *string delimiter
 * Returns: vector<string> The split string 
 */
vector<string> split(string s,string delimiter){
    size_t pos = 0;
    vector<string> tokens;
    while ((pos = s.find(delimiter)) != string::npos) {
        tokens.push_back(s.substr(0, pos));
        s.erase(0, pos + delimiter.length());
    }
    tokens.push_back(s);
    return tokens;
}
/**
 * Public : randomChoice
 * Description:Chooses a random item 
 * Parameters: vector<string> choices
 * Returns: The choice that was randomly picked 
 */
string randomChoice(vector<string> choices){
    return choices[rand() % choices.size()];
}
