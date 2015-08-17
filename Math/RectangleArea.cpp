Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area

Assume that the total area is never beyond the maximum possible value of int.


//两个面积相加  减掉 重复的部分
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
        
        int S1 = (C-A)*(D-B);
        int S2 = (G-E)*(H-F);
        if(C < E || G < A || H < B || D < F)
        {
            return S1 + S2; // no intersection
        }
        int xi_left = max(A, E);
        int yi_left = max(B, F);
        int xi_right = min(C, G);
        int yi_right = min(D, H);
    
        return S1 + S2 - (xi_right - xi_left)*(yi_right - yi_left);
}