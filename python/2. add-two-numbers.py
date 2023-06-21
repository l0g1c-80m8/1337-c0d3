# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# lc sol start
def parse_list(head_node):
    num = head_node.val
    list_node = head_node
    ctr = 0
    while (list_node := list_node.next) is not None:
        num += (10 ** (ctr := ctr + 1)) * list_node.val
    return num


def construct_list(num):
    head_node = ListNode(num % 10)
    list_node = head_node
    while (num := num // 10) > 0:
        list_node.next = ListNode(num % 10)
        list_node = list_node.next
    return head_node


def add_two_numbers(l1, l2):
    return construct_list(parse_list(l1) + parse_list(l2))
# lc sol end


def main():
    n1, n2 = 942, 9465
    solution = add_two_numbers(construct_list(n1), construct_list(n2))
    print('\nSolution: {}\n'.format(parse_list(solution)))
    assert n1 + n2 == parse_list(solution), f"expected {n1 + n2}, got {parse_list(solution)}"


if __name__ == '__main__':
    main()
