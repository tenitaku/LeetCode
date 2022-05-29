/*
 An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

 You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image starting from the pixel image[sr][sc].

 To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with newColor.

 Return the modified image after performing the flood fill.
 
 Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2
 Output: [[2,2,2],[2,2,0],[2,0,1]]
 Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
 Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
 
 m == image.length
 n == image[i].length
 1 <= m, n <= 50
 0 <= image[i][j], newColor < 2^16
 0 <= sr < m
 0 <= sc < n
 */

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if (color != newColor) dfs(image, sr, sc, color, newColor);
        return image;
    }
public:
    void dfs(vector<vector<int>>& image, int i, int j, int color, int newColor) {
        if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] != color) return;
        image[i][j] = newColor;
        dfs(image, i, j - 1, color, newColor);
        dfs(image, i, j + 1, color, newColor);
        dfs(image, i - 1, j, color, newColor);
        dfs(image, i + 1, j, color, newColor);
    }
};

/*
 ポイント：再帰を用いる、再帰ではないが、関数の中で自身を呼び出す。
 ・左右上下に対して、繋がっているところまでnewColorにしていくという考え。
 深さ優先探索とは「とにかく行けるとこまで行ってそれ以上進めなくなったら一歩戻ってそこから探索する」という探索方法。
 幅優先探索とは「出発点に近い点から順に探索する」という探索方法。
 今回はどちらとも言える。幅優先探索に近いかもしれない。一歩戻らないから。
 */
