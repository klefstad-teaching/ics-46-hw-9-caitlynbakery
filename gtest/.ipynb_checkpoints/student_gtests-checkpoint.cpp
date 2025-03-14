#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <stack>

#include "../src/dijkstras.h"
#include "../src/ladder.h"

TEST(Ladder, LoadingWords) {
    set<string> my_words;
    load_words(my_words, "./src/words.txt");
    EXPECT_TRUE(my_words.size() == 45392);
}

TEST(Ladder, IsAdjacent){
    EXPECT_TRUE(is_adjacent("cat", "car"));
    EXPECT_TRUE(is_adjacent("reading", "readin"));
    EXPECT_TRUE(is_adjacent("baker", "bakers"));
    EXPECT_FALSE(is_adjacent("karma", "time"));
    EXPECT_FALSE(is_adjacent("meep", "moop"));
}

TEST(Ladder, EditDistances){
    EXPECT_TRUE(edit_distance_within("morp", "meep", 2));
    EXPECT_FALSE(edit_distance_within("cake", "cupcake", 2));
    EXPECT_FALSE(edit_distance_within("tired", "hungry", 2));
}

TEST(Ladder, ErrorGenerateWordLadder){
    set<string> my_words;
    load_words(my_words, "./src/words.txt");
    vector<string> my_ladder =  generate_word_ladder("hungry","hungry", my_words);
    EXPECT_TRUE(my_ladder == vector<string>());
}

TEST(Ladder, GenerateWordLadder){
    set<string> my_words;
    load_words(my_words, "./src/smallwords.txt");
    vector<string> my_ladder =  generate_word_ladder("pat","hatched", my_words);
    print_word_ladder(my_ladder);
    EXPECT_TRUE(my_ladder.size() == 7);
}

TEST(Ladder, LastErrorGenerateWordLadder){
    set<string> my_words;
    load_words(my_words, "./src/smallwords.txt");
    vector<string> my_ladder =  generate_word_ladder("pat","caitlyn", my_words);
}

TEST(Ladder, VerifyLadder){
    verify_word_ladder();
}