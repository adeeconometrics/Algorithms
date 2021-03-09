#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<int>> vec;
    int row, col;
    int query;
    std::cin>>row>>query;
    
    // constraints 
    if(row>10e5) std::cerr<<"row must not exceed "<<10e5;
    if(query>10e5) std::cerr<<"query must not exceed "<<10e5;
    
    for(int i = 0; i<row; i++){
        std::vector<int> v1;
        std::cin>>col;
        if(col>3*10e5) std::cerr<<"column must not exceed "<<3*10e5;
        
        for(int j=0; j<col; j++){
            int num;
            std::cin>>num;
            v1.push_back(num);
        }
        vec.push_back(v1);
    }
    
    for(int j = 0; j<query; j++){
        int temp_r, temp_c;
        std::cin>>temp_r>>temp_c;
        std::cout<<vec[temp_r][temp_c]<<std::endl;
    }
}
