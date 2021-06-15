final class Node{
    var data:Int;
    var next:Node? = nil;

    init(m_data:Int) {data = m_data;}
    // init(){}
}

class Stack{
    private var front:Node? = nil;
    private var back:Node? = nil;
    private var m_size:Int = 0;

    func push(data:Int){
        var node:Node = Node(data);
        if isEmpty(){
            self.front = node;
            self.back = node;
        }
        else{
            node.next = self.front;
            self.front = node;
        }
        self.m_size += 1;
    }

    func pop(){ // how GC is managed in swift?
        if isEmpty(){
            return;
        }
        self.front = self.front.next;
        self.m_size -= 1;
    }

    func display(){
        var ptr:Node? = self.front;
        while(ptr.next != nil){
            print(" \(ptr.data)");
            ptr = ptr.next;
        }
    }

    func isEmpty()->Bool{return head == nil;}
}