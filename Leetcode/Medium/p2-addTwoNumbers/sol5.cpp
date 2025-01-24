
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* temp1 = l1;
    int x = 0;
    int y = 0;
    int ten = 1;

    // Convert the linked list values to integers
    while (temp1 != nullptr) {
        x += (temp1->val * ten);
        temp1 = temp1->next;
        ten *= 10;
    }

    ten = 1;
    temp1 = l2;
    while (temp1 != nullptr) {
        y += (temp1->val * ten);
        temp1 = temp1->next;
        ten *= 10;
    }

    int z = x + y;

    // Create a new linked list to store the result
    ListNode* ll = new ListNode(z % 10);
    z /= 10;

    // Use a pointer to traverse the result linked list
    ListNode* ptr = ll;

    // Corrected loop condition and assignments inside the loop
    while (z != 0) {
        ListNode* newNode = new ListNode(z % 10);
        z /= 10;
        ptr->next = newNode;
        ptr = newNode;
    }

    return ll;
}


};