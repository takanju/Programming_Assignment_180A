/**
 * Test the binary search tree and AVL tree implementations.
 * The AVL tree is derived from the binary search tree.
 *
 * Create a tree of height 5 and then repeatedly
 * delete the root. The AVL tree should remain balanced
 * after each node insertion and deletion.
 *
 * Author: Ron Mak
 *         Department of Computer Engineering
 *         San Jose State University
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>
#include <chrono>
#include <time.h>

#include "BinarySearchTree.h"
#include "AvlTree.h"

using namespace std;
using namespace std::chrono;

// Tree statistics.
struct Stats
{
    long probe_count;
    long compare_count;
    long elapsed_time;
};

// Operations
const string INSERT = "insert";
const string SEARCH = "search";
const vector<string> OPERATIONS = {INSERT, SEARCH};

// Tree type
const string BST = "bst";
const string AVL = "avl";
const vector<string> TYPES = {BST, AVL};

// A three-dimensional map of tree statistics,
// keyed by operation, data size, and tree type.
typedef map<string, map<int, map<string, Stats>>> StatsMap;

/**
 * Test the trees.
 * @param stats_map map of insertion and search statistics.
 * @param N the vector of tree sizes.
 */
void test_trees(StatsMap& stats_map, vector<int>& N);

/**
 * Insert values into a tree.
 * @param tree the BST or AVL tree.
 * @param data the data values to insert.
 * @param type "BST" or "AVL".
 * @param stats_map map of insertion and search statistics.
 */
void insert_tree(BinarySearchTree& tree, vector<long>& data,
                 const string& type, StatsMap& stats_map);

/**
 * Search a tree.
 * @param tree the BST or AVL tree.
 * @param data the data values to find.
 * @param type "BST" or "AVL".
 * @param stats_map map of insertion and search statistics.
 */
void search_tree(BinarySearchTree& tree, vector<long>& data,
                 const string& type, StatsMap& stats_map);

/**
 * Dump the insertion and search statistics in the CSV format.
 * @param stats_map map of insertion and search statistics.
 * @param N the vector of tree sizes.
 */
void dump_stats_map(StatsMap& map, vector<int> N);

/**
 * Main.
 */
int main( )
{
    StatsMap stats_map;
    vector<int> N;

    srand(time(NULL));  // seed the random number generator
    for (int n = 10000; n <= 100000; n += 10000) N.push_back(n);

    test_trees(stats_map, N);
    dump_stats_map(stats_map, N);
}

void test_trees(StatsMap& stats_map, vector<int>& N)
{
    for (int size : N)
    {
        BinarySearchTree bst;
        AvlTree avl;
        vector<long> insertion_data, search_data;

        for (int i = 1; i <= size; i++) insertion_data.push_back(rand());
        for (int i = 1; i <= size; i++) search_data.push_back(rand());

        insert_tree(bst, insertion_data, BST, stats_map);
        insert_tree(avl, insertion_data, AVL, stats_map);

        search_tree(bst, search_data, BST, stats_map);
        search_tree(avl, search_data, AVL, stats_map);
    }
}

void insert_tree(BinarySearchTree& tree, vector<long>& data,
                 const string& type, StatsMap& stats_map)
{
    steady_clock::time_point start_time = steady_clock::now();
    Stats stats;

    tree.reset_probe_count();
    tree.reset_compare_count();

    for (long value : data) tree.insert(value);

    steady_clock::time_point end_time = steady_clock::now();
    stats.elapsed_time = duration_cast<milliseconds>(end_time - start_time).count();

    stats.probe_count = tree.get_probe_count();
    stats.compare_count = tree.get_compare_count();

    cout << INSERT << " " << data.size() << " " << type << " = "
         << stats.probe_count << " " << stats.compare_count
         << " " << stats.elapsed_time << endl;

    stats_map[INSERT][data.size()][type] = stats;
}

void search_tree(BinarySearchTree& tree, vector<long>& data,
                 const string& type, StatsMap& stats_map)
{
    steady_clock::time_point start_time = steady_clock::now();
    Stats stats;

    tree.reset_probe_count();
    tree.reset_compare_count();

    for (long value : data) tree.contains(value);

    steady_clock::time_point end_time = steady_clock::now();
    stats.elapsed_time = duration_cast<milliseconds>(end_time - start_time).count();

    stats.probe_count = tree.get_probe_count();
    stats.compare_count = tree.get_compare_count();

    cout << SEARCH << " " << data.size() << " " << type << " = "
         << stats.probe_count << " " << stats.compare_count
         << " " << stats.elapsed_time << endl;

    stats_map[SEARCH][data.size()][type] = stats;
}

void dump_stats_map(StatsMap& map, vector<int> N)
{
    // Loop for each operation.
    for (string operation : OPERATIONS)
    {
        cout << endl << "Probes for " << operation << endl;
        cout << "N,BST,AVL" << endl;

        // Loop for each data size.
        for (int n : N)
        {
            cout << n;

            // Loop for each tree type.
            for (string type : TYPES)
            {
                Stats stats = map[operation][n][type];
                cout << "," << stats.probe_count;  // dump probe counts
            }

            cout << endl;
        }
    }

    // Loop for each operation.
    for (string operation : OPERATIONS)
    {
        cout << endl << "Compares for " << operation << endl;
        cout << "N,BST,AVL" << endl;

        // Loop for each data size.
        for (int n : N)
        {
            cout << n;

            // Loop for each tree type.
            for (string type : TYPES)
            {
                Stats stats = map[operation][n][type];
                cout << "," << stats.compare_count;  // dump compare counts
            }

            cout << endl;
        }
    }

    // Loop for each operation.
    for (string operation : OPERATIONS)
    {
        cout << endl << "Elapsed ms for " << operation << endl;
        cout << "N,BST,AVL" << endl;

        // Loop for each data size.
        for (int n : N)
        {
            cout << n;

            // Loop for each tree type.
            for (string type : TYPES)
            {
                Stats stats = map[operation][n][type];
                cout << "," << stats.elapsed_time;  // dump elapsed ms
            }

            cout << endl;
        }
    }
}
