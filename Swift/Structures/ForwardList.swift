class Node{
    var data:Int = 0;
    var next:Node? = nil;

    init(m_data:Int) {data = m_data;}
}

class ForwardList{
    private var front:Node? = nil;
    private var back:Node? = nil;
    private var m_size:Int = 0;

    func add(data:Int){
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

    func add_back(data:Int){
        let node:Node = Node(m_data:data);
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

    func add_front(data:Int){
        var node:Node = Node(data);
        if isEmpty(){
            self.front = node;
            self.back = node;
        }
        else{
            node?.next = self.front;
            self.front = node;
        }
        self.m_size += 1;
    }

    func remove_front(){ // how GC is managed in swift?
        if isEmpty(){
            return;
        }
        self.front = self.front!.next;
        self.m_size -= 1;
    }

    // func remove_back(){
    //     if isEmpty(){
    //         return;
    //     }
    //     self.back = self.back.prev;
    //     self.m_size -= 1;
    // }

    func remove(data:Int){
        if isEmpty(){
            return;
        }
        else{
            var ptr:Node? = self.front;
            var prev:Node? = ptr;

            while (ptr?.next != nil){
                if(ptr!.data == data){
                    prev?.next = ptr?.next;

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
}

var l = ForwardList();

var i:Int = 10;

while (i > 0){
    l.add_back(data:i);
    i -= 1;
}

l.display();