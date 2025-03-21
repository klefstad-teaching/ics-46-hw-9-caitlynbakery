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
    EXPECT_TRUE(is_adjacent("apple", "apple"));
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
    EXPECT_TRUE(edit_distance_within("apple", "apple",1));
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


TEST(Dijkstras, DijkstraTest){
    Graph G;
    file_to_graph("./src/small.txt", G);
    vector<int> prev(G.size());
    vector<int> shortest_path = dijkstra_shortest_path(G, 0, prev);
    cout << "Shortest path " << endl;
    for(auto path: shortest_path){
        cout << path << " ";
    }
    
}

TEST(Dijkstras, ShortestDijkstraTest){
    Graph G;
    file_to_graph("./src/small.txt", G);
    vector<int> prev(G.size());
    vector<int> shortest_path = dijkstra_shortest_path(G, 0, prev);
    cout << "BEFORE EXTRACT " << endl;
    vector<int> extract = extract_shortest_path(shortest_path, prev, 1);
    for (auto e: extract){
        cout << e << " ";
    }
}

TEST(Dijkstras, MediumDijkstraTest){
    Graph G;
    file_to_graph("./src/medium.txt", G);
    vector<int> prev(G.size());
    vector<int> shortest_path = dijkstra_shortest_path(G, 0, prev);
    cout << "BEFORE EXTRACT " << endl;
    vector<int> extract = extract_shortest_path(shortest_path, prev, 4);
    for (auto e: extract){
        cout << e << " ";
    }
}
// TEST(Ladder, VerifyLadder){
//     verify_word_ladder();
// }