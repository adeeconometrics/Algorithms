final class Node{
    var data:Int = 0;
    var next:Node? = nil;
    var prev:Node? = nil;

    init(m_data:Int) {data = m_data;}
}

class OrderedList{
    private var front:Node? = nil;
    private var back:Node? = nil;
    private var m_size:Int = 0;

    func add(data:Int){
        var node:Node = Node(data);
        if isEmpty(){
            self.front = node;
            self.back = node;
        }
        else if data >= self.front!.data {
            node?.next = self.front;
            self.front?.prev = node;
            self.front = node;
        }
        else if data <= self.back!.data {
            self.back?.next = node;
            node?.prev = self.back;
            self.back = node;
        }
        else{
            var ptr:Node? = self.front;

            while(ptr?.next != nil){
                if ptr!.next.data < data{
                    break;
                }
                ptr = ptr?.next;
            }

            if(ptr?.next != nil){
                ptr?.next.prev = node;
                node?.next = ptr?.next;
                node?.prev = ptr;
                ptr?.next = node;
            }
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

    func remove(data:Int){
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