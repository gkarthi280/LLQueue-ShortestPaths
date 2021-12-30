#include "proj2.hpp"
#include <iostream>
#include <vector>

namespace{

    //calculates the bunmber of Shoterst paths given the previous vector and target destination
    unsigned numberShortestPaths(std::vector<std::vector<int>> & previous, unsigned target)
    {
        unsigned counter = 0;
        if(target == -1)
        {
            return 1;
        }
        for(unsigned i: previous[target])
        {
            counter += numberShortestPaths(previous, i);
        }
        return counter;
    }
}
void countPaths(const std::vector< std::vector<unsigned> > & friends, unsigned start, std::vector<unsigned> & pathLengths, std::vector<unsigned> & numShortestPaths)
{
    LLQueue<unsigned> nodes;
    std::vector<bool> visited;
    std::vector<std::vector<int>> previous(friends.size());
    previous[start].push_back(-1);
    nodes.enqueue(start);
    for(int i = 0; i <= friends.size() - 1; i++)
    {
        visited.push_back(false);
    }
    visited[start] = true;
    for(auto i: pathLengths)
    {
        pathLengths[i] = 0;
    }
    while (nodes.isEmpty() == false)
    {
        unsigned node = nodes.front();
        nodes.dequeue();
        for(unsigned neighbor: friends[node])
        {
            if(visited[neighbor] == false)
            {
                visited[neighbor] = true;
                nodes.enqueue(neighbor);
                pathLengths[neighbor] = pathLengths[node] + 1;      
                previous[neighbor].push_back(node);       
            }
            else
            {
                unsigned temp_length = pathLengths[node] + 1; 
                if(temp_length == pathLengths[neighbor])
                {
                    previous[neighbor].push_back(node);
                }
            }
            
        }
    }
   
    for(unsigned i = 0; i < numShortestPaths.size(); i++)
    {
        numShortestPaths[i] = numberShortestPaths(previous, i);

    }


}
