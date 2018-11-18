#include <iostream>
#include <string>
#include <queue>

template <typename Key,typename Value>
class  BST{
public:
  BST(){
    root = NULL;
    count = 0;
  }
  ~BST(){
    destroy(root);
  }
  int size() { return count; }
  bool isEmpty() { return count == 0; }
  Node insert(Key key,Value value){
    root = insert(root,key,Value value);
  }
  bool  contain(Key key){
    return  contain(root,key);
  }
  Value *serach(Key key){
    return serach(root,key);
  }
   // 二分搜索树的前序遍历
  void preOrder() {
    preOrder(root);
  }
  // 二分搜索树的中序遍历
  void  inOrder(){
    inOrder(root);
  }
  // 二分搜索树的后序遍历
  void  postOrder(){
    postOrder(root);
  }
    // 二分搜索树的level遍历
  void  levelOrder(){
    queue<Node*> q;
    q.push(root);
    while( !q.IsEmpty() ){
      Node *node = q.pop();
      std::cout << node->value << std::endl;

      if( node->left )
        q.push(node->left);
      if( node->right )
        q.push(q->right);
    }
  }
  void removeMin(){
    root = remove(root);
  }
  void removeMax() {
    root = removeMax(root);
  }
  void remove(Key key){
    root = remove(root,key);
  }
private:
  // 向以node为根的二分搜索树中, 插入节点(key, value), 使用递归算法
   // 返回插入新节点后的二分搜索树的根
  Node  *insert(Node* node,Key key,Value value){
    if(node == NULL){
      count++;
      return new Node(key,value);
    }
    if(key == node->key)
      node->value = value;

    if(node->key < key)
      node->left = insert(node->left,key,value);
    else
      node->right = insert(node->right,key,value);

    return node;

  }
  bool contain(Node *node,Key key){
    if(node == NULL)
      return false;

    if(node->key == key)
      return true;
    else if(node->key < key)
      return contain(node->right,key);
    else
      return contain(node->left,key);
  }
  // 在以node为根的二分搜索树中查找key所对应的value, 递归算法
    // 若value不存在, 则返回NULL
  Value *serach(Node *node,Key key){
    if(node == NULL)
      return NULL;

    if(node->key == key)
      return   &(node->value);
    else if(node->key > key)
      return serach(node->left,key);
    else
      return serach(node->right,key);
  }
  void destroy(Node *node){
    if(node != NULL){
      destroy(node->left);
      destroy(node->right);
      delete node;
    }
  }
  void preOrder(Node *node) {

    if(node != NULL){
      std::cout << node->value << std::endl;
      inOrder(node->left);
      inOrder(node->right);
    }
  }
  void  inOrder(Node *node){

    if(node != NULL){
      inOrder(node->left);
      std::cout << node->value << std::endl;
      inOrder(node->right);
    }
  }
  void  postOrder(){
    if(node != NULL){
      inOrder(node->left);
      inOrder(node->right);
      std::cout << node->value << std::endl;
    }
  }
  Node *removeMin(Node *node){
    if( node->left == NULL){
      Node* right = node->right;
      delete  node;
      return  right;
    }

    node->left = removeMin(left);
  }
  Node *removeMax(Node *node){
    if( node->right == NULL){
      Node* left = node->left;
      delete  node;
      return  left;
    }

    node->right = removeMin(riht);
  }
  // 删除掉以node为根的二分搜索树中键值为key的节点, 递归算法
    // 返回删除节点后新的二分搜索树的根
  Node *remove(Node *node,Key key){
    if(node == NULL)
      return NULL;

    if( node->key > key){
      node->left = remove(node->left,key);
      return  node;
    }
    else if( node->key < key){
      node->right = remove(right,key);
      return  node;
    }
    else{
      if(node->left == NULL){
        Node* right = node->right;
        delete node;
        count--;
        return  right;
      }

      if(node->right == NULL){
        Node *left = node->left;
        delete node;
        count--;
        return  left;
      }
      // 待删除节点左右子树均不为空的情况
      // 找到比待删除节点大的最小节点, 即待删除节点右子树的最小节点
     // 用这个节点顶替待删除节点的位置
      Node *successor = new Node(minimum(node->right));
      count++;
      successor->riht = removeMin(node->right);
      successor->left = node->left;
      delete node;
      count--;
      return successor;
    }
  }
  Node *minimum(Node *node){
    if(node->left == NULL)
        return Node;
    return findMin(node->left);
  }
  Node *maxnum(Node *node){
    if( node-> right == NULL)
      return node;

    return  maxnum(node->right);
  }
  struct Node{
    Key key;
    Value value;
    Node *left;
    Node *right;
  };
  Node(Key key,Value value) {
    this->key = key;
    this->value = value;
    this->left = this->right = NULL;
  };
  Node(Node *node) {
    this->key = node->key;
    this->value = node->value;
    this->left = node->left;
    this->right = node->right;
  }
  Node *root;
  int  count;
};
