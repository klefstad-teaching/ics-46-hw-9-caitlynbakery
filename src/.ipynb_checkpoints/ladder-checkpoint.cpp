#include <iostream>
#include <fstream>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include "ladder.h"

using namespace std;

void error(string word1, string word2, string msg){
    cerr << word1 << " " << word2 << " " << msg << endl;
}

#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}


void verify_word_ladder() {
    set<string> word_list;
    load_words(word_list, "./src/words.txt");
    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}

void print_word_ladder(const vector<string>& ladder){
    for(auto l : ladder){
        cout << l << " ";
    }
}
void load_words(set<string> & word_list, const string& file_name){
    ifstream myFile;
    myFile.open(file_name);
    string line;
    if(myFile.is_open()){
        while (getline(myFile,line))
        {
            word_list.insert(line);
        }
        myFile.close();
    } else {
        error("File Error", "Load Words", "File not opened");
    }
}

bool is_adjacent(const string& word1, const string& word2){
    //A neighbor of a given word w is a word that differs by exactly 1 letter from w
    return edit_distance_within(word1, word2, 1);
}

//https://www.geeksforgeeks.org/check-if-two-given-strings-are-at-edit-distance-one/
//Below code referenced from Geeks for Geeks example
bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    int m = str1.length();
    int n = str2.length();
    if(abs(m-n) > d){
        return false;
    }
    int count = 0;
    int i = 0, j = 0;
    while (i < m && j < n){
        if(str1[i] != str2[j]){
            if(count >= d){
                return false;
            }
            if (m > n){
                i++;
            } else if (m < n){
                j++;
            } else {
                i++;
                j++;
            }
            count++;
        } else{
            i++;
            j++;
        }
    }
    if (i < m || j < n){
        count++;
    }
    return count == d;
}


vector<string> generate_word_ladder(const string&begin_word, const string& end_word, const set<string>& word_list){
   
    if(begin_word == end_word){
        error(begin_word, end_word, "equal values!");
        return vector<string>();
    }
    if(!word_list.contains(end_word)){
        error("Generate Word Ladder", end_word, "not in word list");
    }
    vector<string> result;
    queue<vector<string>> ladder_queue;    
    ladder_queue.push({begin_word});
    set<string> visited;
    visited.insert(begin_word);
    while (!ladder_queue.empty()){
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();
        string last_word = ladder.back();
        for (auto word: word_list){
            if (is_adjacent(last_word, word)){
                if (!visited.contains(word)){
                    visited.insert(word);
                    vector<string> new_ladder(ladder);
                    new_ladder.push_back(word);
                    if(word == end_word){
                        return new_ladder;
                    } 
                    ladder_queue.push(new_ladder);
                }
            }
        }}
    return vector<string>();
    }
    
