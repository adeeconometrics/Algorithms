final class Node{
    var data:Int = 0;
    var next:Node? = nil;

    init(m_data:Int) {data = m_data;}
}

class Queue{
    private var front:Node? = nil;
    private var back:Node? = nil;
    private var m_size:Int = 0;

    func enqueue(data:Int){
        var node:Node = Node(data);
        if isEmpty(){
            self.front = node;
            self.back = node;
        }
        else{
            self.back?.next = node;
            self.back = node;
        }
        self.m_size += 1;
    }

    func dequeue(){ // how GC is managed in swift?
        if isEmpty(){
            return;
        }
        self.front = self.front?.next;
        self.m_size -= 1;
    }

    func display(){
        var ptr:Node? = self.front;
        while(ptr?.next != nil){
            print(" \(ptr!.data)");
            ptr = ptr?.next;
        }
    }

    func isEmpty()->Bool{return self.front == nil;}

    func size()->Int{return self.m_size; }
}