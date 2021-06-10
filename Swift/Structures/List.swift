final class Node{
    var data:Int;
    var next:Node? = nil;
    var prev:Node? = nil;

    init(m_data:Int) {data = m_data;}
    // init(){}
}

class List{
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
            self.back.next = node;
            node.prev = self.back;
            self.back = node;
        }
        self.m_size += 1
    }

    func remove(data:Int){
        if isEmpty{
            return;
        }
        else{
            var ptr:Node? = self.front
            while (ptr.next != nil){
                if(ptr.data == data){
                    // ptr.prev = ptr.next.
                }
            }
        }
    }


    func isEmpty()->Bool{return head == nil;}
    
}