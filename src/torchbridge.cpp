//
//
//  Created by rregar on 6/24/20.
//  Copyright © 2020 Ram. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include "yaml-cpp/yaml.h"


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <config filename>" << std::endl;
        exit(0);
    }
 
    // Load all test descriptions (YAML documents) as a vector
    std::vector<YAML::Node> tests = YAML::LoadAllFromFile(argv[1]);
    
    for(auto& t : tests)
    {
        YAML::Node data = t["test"];
        
        // test parameters
        int test_id = data["test_id"].as<int>();
        int bridgecount = data["bridgecount"].as<unsigned int>();
        
        std::cout << "Test Id : " << test_id << " bridge count : " << bridgecount << std::endl;
        for (int c = 0; c < bridgecount; c++)
        {
            std::string query("walk_time" + std::to_string(c));
            std::vector<int> walk_time = data[query.c_str()].as<std::vector<int>>();
            int received = 0;
            for (int j = 0; j < walk_time.size(); j++)
            {
                std::cout << walk_time[j] << " " ;
            }
            std::cout << "\nTotal Taken :" << received << std::endl;
        }
    }
    exit(0);
}
