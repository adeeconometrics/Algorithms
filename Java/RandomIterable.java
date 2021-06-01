public interface RandomIterable<T> {
    public boolean hasNext();
    public void next();
    public void insert(T data);
    public void remove(T data);
    public void back_inserter(T data);
    public void front_inserter(T data);
}
