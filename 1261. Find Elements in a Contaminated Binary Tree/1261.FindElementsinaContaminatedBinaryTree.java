

/*

1261. Find Elements in a Contaminated Binary Tree

Given a binary tree with the following rules:

    1. root.val == 0
    2. For any treeNode:
        1. If treeNode.val has a value x and treeNode.left != null, then treeNode.left.val == 2 * x + 1
        2. If treeNode.val has a value x and treeNode.right != null, then treeNode.right.val == 2 * x + 2

Now the binary tree is contaminated, which means all treeNode.val have been changed to -1.

Implement the FindElements class:
    - FindElements(TreeNode* root) Initializes the object with a contaminated binary tree and recovers it.
    - bool find(int target) Returns true if the target value exists in the recovered binary tree.


Example 1:
    Input
    ["FindElements","find","find"]
    [[[-1,null,-1]],[1],[2]]
    Output
    [null,false,true]
    Explanation
    FindElements findElements = new FindElements([-1,null,-1]); 
    findElements.find(1); // return False 
    findElements.find(2); // return True 

Example 2:
    Input
    ["FindElements","find","find","find"]
    [[[-1,-1,-1,-1,-1]],[1],[3],[5]]
    Output
    [null,true,true,false]
    Explanation
    FindElements findElements = new FindElements([-1,-1,-1,-1,-1]);
    findElements.find(1); // return True
    findElements.find(3); // return True
    findElements.find(5); // return False

Example 3:
    Input
    ["FindElements","find","find","find","find"]
    [[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]
    Output
    [null,true,false,false,true]
    Explanation
    FindElements findElements = new FindElements([-1,null,-1,-1,null,-1]);
    findElements.find(2); // return True
    findElements.find(3); // return False
    findElements.find(4); // return False
    findElements.find(5); // return True


Constraints:
    - TreeNode.val == -1
    - The height of the binary tree is less than or equal to 20
    - The total number of nodes is between [1, 104]
    - Total calls of find() is between [1, 104]
    - 0 <= target <= 106

*/


/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */


class FindElements {

    ArrayList<Integer> visitats; 

    public FindElements(TreeNode root) {
        visitats = new ArrayList<>();
        inicialize(root);
    }

    public void inicialize(TreeNode node){
        Queue<TreeNode> queue = new LinkedList<>();
        node.val = 0;
        queue.add(node);

        while(!queue.isEmpty()){
            TreeNode node_actual = queue.remove();

            visitats.add(node_actual.val);
            if(node_actual.left != null){
                node_actual.left.val = 2 * node_actual.val + 1;
                queue.add(node_actual.left);
            }
            if(node_actual.right != null){
                node_actual.right.val = 2 * node_actual.val + 2;
                queue.add(node_actual.right);
            }
        }
    }

    public boolean find(int target) {
        return visitats.contains(target);
    }
}

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements obj = new FindElements(root);
 * boolean param_1 = obj.find(target);
 */