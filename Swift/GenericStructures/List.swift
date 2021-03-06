final class Node<T: Comparable>{
    lazy var data:T;
    var next:Node? = nil;
    var prev:Node? = nil;

    init(m_data:T) {data = m_data;}
}

class List<T: Comparable>{
    private var front:Node? = nil;
    private var back:Node? = nil;
    private var m_size:Int = 0;

    func add(data:T){
        var node:Node = Node(data);
        if isEmpty(){
            self.front = node;
            self.back = node;
        }
        else{
            self.back?.next = node;
            node.prev = self.back;
            self.back = node;
        }
        self.m_size += 1;
    }

    func add_back(data:T){
        var node:Node = Node(data);
        if isEmpty(){
            self.front = node;
            self.back = node;
        }
        else{
            self.back?.next = node;
            node.prev = self.back;
            self.back = node;
        }
        self.m_size += 1;
    }

    func add_front(data:T){
        var node:Node = Node(data);
        if isEmpty(){
            self.front = node;
            self.back = node;
        }
        else{
            node.next = self.front;
            self.front?.prev = node;
            self.front = node;
        }
        self.m_size += 1;
    }

    func remove_front(){ // how GC is managed in swift?
        if isEmpty(){
            return;
        }
        self.front = self.front?.next;
        self.m_size -= 1;
    }

    func remove_back(){
        if isEmpty(){
            return;
        }
        self.back = self.back?.prev;
        self.m_size -= 1;
    }

    func remove(data:T){
        if isEmpty(){
            return;
        }
        else{
            var ptr:Node? = self.front;
            var prev:Node? = self.ptr;

            while (ptr?.next != nil){
                if(ptr!.data == data){
                    prev?.next = ptr?.next;
                    ptr?.next.prev = prev;

                    self.m_size -= 1;
                    return; 
                }
                prev = ptr;
                ptr = ptr?.next;
            }
        }
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