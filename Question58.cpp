58 -> FLOOD FILL

Solution :
class Solution {
public:
    bool valid(vector<vector<int>>& image, int sr, int sc, int color,int curr){
        if(sr>=0&&sr<image.size()&&sc>=0&&sc<image[0].size()&&image[sr][sc]==curr)
            return true;
        
        return false;
    }
    void dfs(vector<vector<int>>& image, int sr, int sc, int color,int curr){
         image[sr][sc]=color;
        if(valid(image,sr+1,sc,color,curr))
            dfs(image,sr+1,sc,color,curr);
        
          if(valid(image,sr-1,sc,color,curr))
            dfs(image,sr-1,sc,color,curr);
    
          if(valid(image,sr,sc+1,color,curr))
            dfs(image,sr,sc+1,color,curr);
        
          if(valid(image,sr,sc-1,color,curr))
            dfs(image,sr,sc-1,color,curr);
       
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int curr=image[sr][sc];
      if(curr!=color)
        dfs(image,sr,sc,color,curr);
        return image;
    }
};
