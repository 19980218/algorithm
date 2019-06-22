/*非递归中序遍历*/
 2 void LDR_no_recursion(BiTree *T) {
 3     BiTree stack[100];
 4     int top = -1;
 5     if (*T == null)
 6         return;
 7     BiTree p = *T;
 8     while (p) {
 9         stack[++top] = p;
10         p = p->lchild;
11     }
12     while (top != -1) {
13         while (top != -1 && stack[top]->rchild == null){
14             p = stack[top];
15             printf("%c ",p->data);
16             --top;
17         }
18         if (top == -1)
19             return;
20         else {
21             p = stack[top]->rchild;
22             printf("%c ", stack[top]->data);
23             --top;
24             while (p) {
25                 stack[++top] = p;
26                 p = p->lchild;
27             }
28         }
29     }
30 }
31 /*后序非递归遍历*/
32 void LRD_no_recursion(BiTree *T) {
33     
34     if (*T == null)
35         return;
36     SBiTNode st;
37     SBiTNode stack[100];//总是忘记带*
38     int top = -1;
39     BiTree p = *T; 
40     while (p) {
41         top++;
42         stack[top].elem = p;
43         stack[top].flag = 0;
44         p = p->lchild;
45     }
46     while (top != -1) {
47         st = stack[top];
48         if (st.elem->rchild == null || st.flag == 1) {
49             printf("%c ", st.elem->data);
50             --top;
51         }
52         else {
53             stack[top].flag = 1;
54             p = st.elem->rchild;
55             while (p) {
56                 top++;
57                 stack[top].elem = p;
58                 stack[top].flag = 0;
59                 p = p->lchild;
60             }
61         }
62     }
63 }