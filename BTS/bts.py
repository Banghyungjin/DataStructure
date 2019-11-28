class BinaryTree:
    def __init__(self, data):
        self.data = data  # root node
        self.left = None  # left child
        self.right = None  # right child

    def setData(self, data):  # 데이터 값을 setting 합니다.
        self.data = data

    def getData(self):
        return self.data

    def getLeft(self):  # 왼쪽 child node로 갑니다.
        return self.left

    def getRight(self):
        return self.right
    def setNull(self):
        self.data = None
        self.left = None
        self.right = None

    def setThis(self, newNode):
        self.data = newNode.getData()
        self.setLeft(newNode.left)
        self.setRight(newNode.right)

    def setLeft(self, left):  # get left child of a node
        self.left = left

    def setRight(self, right):
        self.right = right

    def insertLeft(self, newNode):  # 현재 위치 노드의 왼쪽에 NewNode를 매어 담.
        if self.left == None:
            self.left = BinaryTree(newNode)
        else:
            temp = BinaryTree(newNode)
            temp.left = self.left
            self.left = temp

    def insertRight(self, newNode):
        if self.right == None:
            self.right = BinaryTree(newNode)
        else:
            temp = BinaryTree(newNode)
            temp.right = self.right
            self.right = temp

    def shrink_left(self):
        self.setThis(self.left)

    def shrink_right(self):
        self.setThis(self.right)


def add_node(root, result):
    if root.getData() is None:
        root.setData(result)
    elif result < root.getData():
        if not root.left:
            root.insertLeft(result)
        else:
            add_node(root.left, result)
    elif result == root.getData():
        return
    else:
        if not root.right:
            root.insertRight(result)
        else:
            add_node(root.right, result)


def delete_node(root, result):
    temp = None
    if root.getData() is not None:
        if result == root.getData():
            if not root.left and not root.right:
                root.setData(None)
            elif root.left:
                temp = find_left_big(root.left, temp)
                root.data = temp.data
                result = temp.data
                erase(root, result)

            else:
                temp = find_right_small(root.right, temp)
                root.data = temp.data
                result = temp.data
                erase(root, result)

        elif result < root.getData() and root.left:
            delete_node(root.left, result)

        elif result > root.getData() and root.right:
            delete_node(root.right, result)


def find_left_big(root, temp):
    if root.right:
        temp = find_left_big(root.right, temp)
    else:
        temp = root
    return temp


def find_right_small(root, temp):
    if root.left:
        temp = find_right_small(root.left, temp)
    else:
        temp = root
    return temp


def erase(root, result):
    if root:
        if root.left:
            if root.left.getData() == result:
                if root.left.left:
                    root.setLeft(root.left.left)
                else:
                    root.setLeft(None)
            else:
                erase(root.left, result)
        elif root.right:
            if root.right.getData() == result:
                if root.right.right:
                    root.setRight(root.right.right)
                else:
                    root.setRight(None)
            else:
                erase(root.right, result)
    else:
        return


def treeSize(root):
    if not root:
        return 0
    else:
        a = treeSize(root.left)
        b = treeSize(root.right)
        return (a + b + 1)


def treeLeaf(root, result):
    if treeSize(root) == 1:
        result.append(root.getData())
        return result
    elif treeSize(root) == 0:
        return result
    else:
        a = treeLeaf(root.left, result)
        b = treeLeaf(root.right, result)
        return result


def depth(root, index, result):
    if index == 1:
        if root:
            result.append(root.data)
    else:
        if root.left:
            depth(root.left, index - 1, result)
        if root.right:
            depth(root.right, index - 1, result)


def PreorderTree(root, result):
    if not root: return
    result.append(root.data)
    PreorderTree(root.left, result)
    PreorderTree(root.right, result)


count = 0
file = open("8.inp", 'r')
answer = open("bts.out",'w')
num_of_command = file.readline()
root = BinaryTree(None)
for a in range(0, int(num_of_command)):
    string = file.readline()
    if string[0] == '+':
        if count == 0:
            add_node(root, string[2:-1])
        else:
            add_node(root, string[2:-1])

    elif string[0] == '-':
        delete_node(root, string[2:-1])
        erase(root, string[2:-1])

    elif string[0:4] == "leaf":
        myout = []
        treeLeaf(root, myout)
        myout.sort()
        if len(myout) == 0:
            myout.append("NO")
        for i in myout:
            if not i is None:
                answer.write(i + " ")
            else:
                answer.write("NO")
        answer.write("\n")

    elif string[0:5] == "depth":
        myout = []
        depth(root, int(string[6:]), myout)
        myout.sort()
        if len(myout) == 0:
            myout.append("NO")
        for i in myout:
            if not i is None:
                answer.write(i + " ")
            else:
                answer.write("NO")
        answer.write("\n")
file.close()
answer.close()
