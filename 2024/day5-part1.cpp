#include <iostream>
#include <map>
#include <string>
#include <vector>

// 47|53
// 97|13
// 97|61
// 97|47
// 75|29
// 61|13
// 75|53
// 29|13
// 97|29
// 53|29

struct Node {
    Node(int val_) { val = val_; }
    int val = 0;
    std::vector<Node*> nexts{nullptr};

    bool operator==(const Node& n) const { return n.val == val; }
};

Node* node_find(std::vector<Node*>& nodes, int val) {
    for (Node* node : nodes) {
        if (node->val == val) {
            return node;
        }
    }
    return nullptr;
}

int main() {
    std::vector<std::vector<int>> correct_orders{};
    std::vector<Node*> nodes{};
    Node* current_node = nullptr;
    /*
    so we want to first create our graph, so that we can do a topological sort
    on int. we need to set up our graph using nodes we then want to use kahn's
    algorithm (removing nodes without dependencies).
    */

    std::string line{};
    while (std::getline(std::cin, line) && line != "ENDOFLINE") {
        // find the first number
        std::string first_number = line.substr(0, line.find("|"));
        std::string second_number =
            line.substr(line.find("|") + 1, line.size());

        Node* first_node = node_find(nodes, std::stoi(first_number));
        if (!first_node) {
            first_node = new Node(std::stoi(first_number));
            nodes.push_back(first_node);
        }

        Node* second_node = node_find(nodes, std::stoi(second_number));
        if (!second_node) {
            second_node = new Node(std::stoi(second_number));
            nodes.push_back(second_node);
        }
        first_node->nexts.push_back(second_node);
    }

    // print the graph
    for (Node* n : nodes) {
        std::cout << n->val << " ";
    }

    // after we have our graph we need to find nodes with no dependencies.
    std::map<Node*, int>
        node_counts{};  // stores the counts of each node referred to in "nexts"
    for (Node* n : nodes) {
        for (auto* x : n->nexts) {
            if (node_counts.contains(x)) {
                node_counts[x]++;
            } else {
                node_counts[x] = 0;
            }
        }
    }

    std::vector<int> order{};

    // after weve got our map, we need to find ones with no dependencies
    while (nodes.size() >= 1) {
        for (auto [key, value] : node_counts) {
            // remove the node from the graph
            if (value == 0 && node_find(nodes, key->val) != nullptr) {
                order.push_back(key->val);
                Node* n = node_find(nodes, key->val);
                n = nullptr;
                // we need some way to erase the value from it.
            }
        }
    }

    // get middle values.
    int total_count = 0;
    for (const auto& v : correct_orders) {
        total_count += v[(v.size() + 1) / 2];
    }
}
