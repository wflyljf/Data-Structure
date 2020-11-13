//����order��(��)��B-TREE�ṹ����������
//���ң�search�����룺insert��ɾ����remove��
//������create�����٣�destory����ӡ��print��
 
#include <stdio.h>
#include "b-tree.h"
 
void test_BTree_search(BTree tree, KeyType key)
{
    int pos = -1;
    BTNode*    node = BTree_search(tree, key, &pos);
    if (node) {
        printf("��%s�ڵ㣨���� %d ���ؼ��֣����ҵ��ؼ��� %c��������Ϊ %d\n",
            node->isLeaf ? "Ҷ��" : "��Ҷ��",
            node->keynum, key, pos);
    }
    else {
        printf("�������Ҳ����ؼ��� %c\n", key);
    }
}
 
void test_BTree_remove(BTree* tree, KeyType key)
{
    printf("\n�Ƴ��ؼ��� %c \n", key);
    BTree_remove(tree, key);
    BTree_print(*tree , 1);
    printf("\n");
}
 
void test_btree()
{
 
    KeyType array[] = {
        'G','G', 'M', 'P', 'X', 'A', 'C', 'D', 'E', 'J', 'K',
        'N', 'O', 'R', 'S', 'T', 'U', 'V', 'Y', 'Z', 'F', 'X'
    };

	/*KeyType array[] = {
        'A' , 'C' , 'G' , 'N'
    };*/

    const int length = sizeof(array)/sizeof(KeyType);
    BTree tree = NULL;
    BTNode* node = NULL;
    int pos = -1;
    KeyType key1 = 'R';        // in the tree.
    KeyType key2 = 'B';        // not in the tree.
 
    // ����
    BTree_create(&tree, array, length);
 
    printf("\n=== ���� B- �� ===\n");
    BTree_print(tree , 1);
    printf("\n");
 
    // ����
    test_BTree_search(tree, key1);
    printf("\n");
    test_BTree_search(tree, key2);
 
	// �Ƴ�����B���е�Ԫ��
	test_BTree_remove(&tree, key2);
	printf("\n");
 
    // ����ؼ���
    printf("\n����ؼ��� %c \n", key2);
    BTree_insert(&tree, key2);
    BTree_print(tree , 1);
    printf("\n");
 
    test_BTree_search(tree, key2);
 
    // �Ƴ��ؼ���
    test_BTree_remove(&tree, key2);
    test_BTree_search(tree, key2);
 
    key2 = 'M';
    test_BTree_remove(&tree, key2);
    test_BTree_search(tree, key2);
 
    key2 = 'E';
    test_BTree_remove(&tree, key2);
    test_BTree_search(tree, key2);
 
    key2 = 'G';
    test_BTree_remove(&tree, key2);
    test_BTree_search(tree, key2);
 
    key2 = 'A';
    test_BTree_remove(&tree, key2);
    test_BTree_search(tree, key2);
 
    key2 = 'D';
    test_BTree_remove(&tree, key2);
    test_BTree_search(tree, key2);
 
    key2 = 'K';
    test_BTree_remove(&tree, key2);
    test_BTree_search(tree, key2);
 
    key2 = 'P';
    test_BTree_remove(&tree, key2);
    test_BTree_search(tree, key2);
 
    key2 = 'J';
    test_BTree_remove(&tree, key2);
    test_BTree_search(tree, key2);
 
    key2 = 'C';
    test_BTree_remove(&tree, key2);
    test_BTree_search(tree, key2);
 
    key2 = 'X';
    test_BTree_remove(&tree, key2);
    test_BTree_search(tree, key2);
 
	key2 = 'O';
    test_BTree_remove(&tree, key2);
    test_BTree_search(tree, key2);
 
	key2 = 'V';
    test_BTree_remove(&tree, key2);
    test_BTree_search(tree, key2);
 
	key2 = 'R';
    test_BTree_remove(&tree, key2);
    test_BTree_search(tree, key2);
 
	key2 = 'U';
    test_BTree_remove(&tree, key2);
    test_BTree_search(tree, key2);
 
	key2 = 'T';
    test_BTree_remove(&tree, key2);
    test_BTree_search(tree, key2);
 
	key2 = 'N';
    test_BTree_remove(&tree, key2);
    test_BTree_search(tree, key2);
	key2 = 'S';
    test_BTree_remove(&tree, key2);
    test_BTree_search(tree, key2);
	key2 = 'Y';
    test_BTree_remove(&tree, key2);
    test_BTree_search(tree, key2);
	key2 = 'F';
    test_BTree_remove(&tree, key2);
    test_BTree_search(tree, key2);
	key2 = 'Z';
    test_BTree_remove(&tree, key2);
    test_BTree_search(tree, key2);
 
	// ����
	BTree_destroy(&tree);
}
 
int main()
{
	test_btree();
 
	return 0;
}
