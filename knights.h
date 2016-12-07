#ifndef KNIGHTS_H
#define KNIGHTS_H

#include <utility>
#include <vector>
#include <algorithm>

using std::pair;
using std::make_pair;
using std::vector;

typedef vector<pair<int,int> > Path;

/** Helper function: adds two pairs of ints */
pair<int,int> operator+(const pair<int,int> & a, const pair<int,int> & b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

// TODO - your code goes here

vector<pair<int,int>> moves (pair<int,int> position){
    vector<pair<int,int>> possibleMoves;
    int one = position.first;
    int two = position.second;
    possibleMoves={
        {one+1,two-2},{one+2,two-1},
        {one+2,two+1},{one+1,two+2},
        {one-1,two+2},{one-2,two+1},
        {one-2,two-1},{one-1,two-2}};
    return possibleMoves;
}

Path legal_moves (int sizeBoard, Path path, pair<int,int> pos){
    Path newPath;
    Path checkMoves=moves(pos);
    copy_if(checkMoves.begin(),checkMoves.end(),std::inserter(newPath,newPath.end()),[sizeBoard,path](pair<int,int>position){
        return (position.first<sizeBoard && position.second<sizeBoard && position.first>=0 && position.second>=0 && std::find(path.begin(), path.end(), position) ==path.end());
        
    });
    return newPath;
    
}


pair<Path,bool> first_tour(int sizeBoard,Path path){
    Path newMoves=legal_moves(sizeBoard,path,path.back());
    Path newPath=path;
    int square = sizeBoard*sizeBoard;
    if (path.size()==square)
        return
    {path,true};
    
    else {
        if (newMoves.size()!=0){
            
            auto iter=newMoves.begin();
            auto iterEnd = newMoves.end();
            while(iter!=iterEnd){
        //for
                newPath.push_back(*iter);
                
                pair<Path,bool> newTour=first_tour(sizeBoard,newPath);
                
                if (newTour.second==true ) return newTour;
                
                else if (*iter==newMoves.back()) {
                    return {path,false};
                }
                
                else iter++;
            }
            
        }
        else {
            return {path,false};
        }
        
    }
}


// Do not edit below this line

#endif
