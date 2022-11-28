#include <string>

typedef std::string TElement;
struct TNode;
typedef TNode * TNodePtr;
struct TNode {
    TElement element;
    TNodePtr left, right;
};
class BST {
    public: // exportable

        BST();
        BST( const BST & );
        ~BST();
        void insert( const TElement );
        void remove( const TElement );
        TNodePtr search( const TElement ) const;
        void preView() const;
        void inView() const;
        void postView() const;
        
    private: // non-exportable

        TNodePtr root;
        void copy( const TNodePtr );
        void destroy( TNodePtr & );
        void removeNode( TNodePtr & );
        void findMinNode( TNodePtr &, TNodePtr & );
        void insert( const TElement, TNodePtr & );
        void remove( const TElement, TNodePtr & );
        TNodePtr search( const TElement, const TNodePtr ) const;
        void preView( const TNodePtr ) const;
        void inView( const TNodePtr ) const;
        void postView( const TNodePtr ) const;
};