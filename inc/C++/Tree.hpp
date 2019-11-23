/*!
*
*	\file		Tree.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\date		November, 09 2019
*
*/
#ifndef HEADER_CPP_TREE
#define HEADER_CPP_TREE

#include "C++/OsDetection.hpp"

namespace mcd {
	typedef long double NodeWeight;

	/*! \brief	The sorting order of the tree */
	enum TREE_SORT {
		ASC,
		DESC
	};

	enum TREE_DIRECTION {
		RIGHT,
		LEFT,
		NONE
	};

	/*!
	* \brief A struct to define a node for the tree
	*/
	template<class T>
	struct Node {
		T values;
		NodeWeight weight;

		bool initialized = false;

		Node<T>* left = nullptr;
		Node<T>* right = nullptr;
	};

	/*!
	* \brief	Function to sort a tree ascendently depending on weights
	*		\param[in]		datas		The datas to compare to
	*		\param[in]		nodeDatas	The datas of the node to compare to \a datas
	*
	*		\return			Return -1/0/1 to say which node to go
	*/
	template<class T>
	TREE_DIRECTION treeAscSorter(std::pair<T, NodeWeight> datas, std::pair<T, NodeWeight> nodeDatas){
		auto w1 = datas.second;
		auto w2 = nodeDatas.second;

		if(w1 < w2){
			return LEFT;
		} else if(w1 > w2){
			return RIGHT;
		} else {
			return NONE;
		}
	}

	/*!
	* \brief	Function to sort a tree descendently depending on weights
	*		\param[in]		datas		The datas to compare to
	*		\param[in]		nodeDatas	The datas of the node to compare to \a datas
	*
	*		\return			Return -1/0/1 to say which node to go
	*/
	template<class T>
	TREE_DIRECTION treeDescSorter(std::pair<T, NodeWeight> datas, std::pair<T, NodeWeight> nodeDatas){
		auto w1 = datas.second;
		auto w2 = nodeDatas.second;

		if(w1 > w2){
			return LEFT;
		} else if(w1 < w2){
			return RIGHT;
		} else {
			return NONE;
		}
	}

	/*!
	*	\class	Tree
	*	\brief	A class to manage a binary tree
	*	\todo	Refactoring
	*/
	template<typename T>
	class Tree {
		public:
			explicit Tree(TREE_SORT sorting = ASC) :
				_root(nullptr)
			{
				this->envoid();
				deleter = &treeDeleter;
				if(sorting == ASC){ comparator = &treeAscSorter; }
				else { comparator = &treeDescSorter; }
				copier = &copyData;
			}
			~Tree(){
				freeTree(_root);
			}

			/*!
			* \brief	Find a value in the tree and return the node and the path to the node
			*		\param[in]		value		The value to find in the tree
			*
			*		\return			Return the node and the path to this node from the root
			*/
			std::pair<Node<T>*, std::string> find(T value){
				if(!_root->initialized){
					return std::make_pair(_root, "");
				}

				std::string path{""};

				auto node = finder(value, _root, path);

				return std::make_pair(node, path);
			}

			/*!
			* \brief	Get the depth on right
			*		\param[in]		node		The root node of the tree
			*
			*		\return			Return the number of nodes on the right
			*/
			size_t getRightCount(Node<T>* node){
				if(node == nullptr){
					return 0;
				}

				size_t i{1};

				while(node->right != nullptr){
					node = node->right;
					i++;
				}

				return i;
			}

			/*!
			* \brief	Get the depth on left
			*		\param[in]		node		The root node of the tree
			*
			*		\return			Return the number of nodes on the left
			*/
			size_t getLeftCount(Node<T>* node){
				if(node == nullptr){
					return 0;
				}

				size_t i{1};

				while(node->left != nullptr){
					node = node->left;
					i++;
				}

				return i;
			}

			/*! \brief	Print the tree */
			void print(){
				this->applyForEach(&printNode);
				std::cout << std::endl;
			}

			/*!
			* \brief	Do something for each node
			*		\param[in]		func			The function to apply
			*
			*		\return			void
			*/
			void applyForEach(void(*func)(Node<T>*, long int)){
				this->GRD(_root, func, 0);
			}

			/*!
			* \brief	Return the height of the tree
			*		\return			Return the height of the tree
			*/
			size_t height(){
				return this->height(_root);
			}

			/*!
			* \brief	Insert datas in the tree
			*		\param[in]		datas		The datas for the new node
			*
			*		\return			void
			*/
			void insert(std::pair<T, NodeWeight> datas){
				bool created{false};

				T values = datas.first;
				NodeWeight weight = datas.second;
			
				if(!_root->initialized){
					_root->values = values;
					_root->weight = weight;
					_root->initialized = true;

					return;
				}

				auto node = _root;

				while(!created){
					if(this->comparator(datas, std::make_pair(node->values, node->weight)) == LEFT){
						if(node->left == nullptr){
							node->left = this->createChild(values, weight);
							created = true;
						} else {
							node = node->left;
						}
					} else if(this->comparator(datas, std::make_pair(node->values, node->weight)) == RIGHT){
						if(node->right == nullptr){
							node->right = this->createChild(values, weight);
							created = true;
						} else {
							node = node->right;
						}
					} else {
						created = true;
					}
				}

				return;
			}

			/*!
			* \brief	Create a binary tree with a custom sort function
			*		\param[in]		datas		All the datas for the tree
			*
			*		\return			void
			*/
			void create(std::vector<std::pair<T, NodeWeight>> datas){
				if(_root != nullptr){
					delete _root;
				}

				_root = new Node<T>;

				for(auto data : datas){
					this->insert(data);
				}
			}

			/*!
			* \brief	Add datas in the tree
			*		\param[in]		data		The data to add
			*		\param[in]		weight		The weight of the data
			*
			*		\return			Return a pointer to the node after treatment
			*/
			void add(T data, NodeWeight weight){
				this->insert(std::make_pair(data, weight));
			}

			/*!
			* \brief	Equilibrate the tree
			*		\param[in]		sort		Choose the sorting order with a TREE_SORT
			*
			*		\return			void
			*/
			void equilibrate(TREE_SORT sort = ASC){
				switch(sort){
					case ASC:
						this->rightBalance();
						break;
					case DESC:
						this->leftBalance();
						break;
				}
			}

			/*!
			* \brief	A setter for the deletion function
			*		\param[in]		func			The function to use on the destroy of the object
			*
			*		\return			void
			*/
			void onDelete(void(*func)(Node<T>*)){
				deleter = nullptr;
				deleter = func;
			}

			/*!
			* \brief	A setter for the comparator function
			*		\param[in]		func			The function to use to the weights' comparison
			*
			*		\return			void
			*/
			void onCompare(void(*func)(Node<T>*, Node<T>*)){
				comparator = nullptr;
				comparator = func;
			}

			/*! \brief	Set the sorter ascending */
			void asc(){
				comparator = nullptr;
				comparator = &treeAscSorter;
			}

			/*! \brief	Set the sorter descending */
			void desc(){
				comparator = nullptr;
				comparator = &treeDescSorter;
			}

		public:
			/*!
			* \brief	Return an array format for the tree
			*		\param[in]		in		The value to convert
			*
			*		\return			Return \a in converted for the tree
			*/
			template<typename U>
			static std::vector<std::pair<T, NodeWeight>> convert(std::vector<std::pair<T, U>> in){
				std::vector<std::pair<T, NodeWeight>> out;

				for(auto vals : in){
					T value = vals.first;
					NodeWeight weight = static_cast<NodeWeight>(vals.second);

					out.push_back(std::make_pair(value, weight));
				}

				return out;
			}

		private:
			/*!
			* \brief	Free the differents nodes of the tree with a function for the node
			*		\param[in]		root		The root node of the tree
			*
			*		\return			void
			*/
			void freeTree(Node<T>* root){
				if(root != nullptr){
					this->freeTree(root->right);
					this->freeTree(root->left);

					this->deleter(root);
					delete root;
				}
			}

			/*!
			* \brief	Find a value in the tree and return the right node
			*		\param[in]		value		The value to find
			*		\param[in]		node		The root node of the tree
			*		\param[in,out]	path		The path to the value in the tree
			*
			*		\return			Return a pointer to the node after treatment
			*/
			Node<T>* finder(T value, Node<T>* node, std::string& path){
				if(node->values == value){
					return node;
				}

				if(node->left == nullptr && node->right == nullptr){
					return nullptr;
				}

				Node<T>* wanted;

				if(node->left != nullptr){
					if((wanted = this->finder(value, node->left, path)) != nullptr){
						path += "0";
						return wanted;
					}
				}
				if(node->right != nullptr){
					if((wanted = this->finder(value, node->right, path)) != nullptr){
						path += "1";
						return wanted;
					}
				}

				return nullptr;
			}

			/*!
			* \brief	
			*		\param[in]		node		The root node of the tree
			*		\param[in]		nodeCount	The number of nodes
			*
			*		\return			Return a pointer to the node after treatment
			*/
			Node<T>* rightBalanceVine(Node<T>* node, size_t nodeCount){
				size_t times = static_cast<size_t>(log2(static_cast<double>(nodeCount)));
				Node<T>* newNode = node;

				for(size_t i{0}; i < times; i++){
					newNode = this->leftRotate(newNode);
					node = newNode->right;

					for(size_t j{0}; j < (nodeCount/2 - 1); j++){
						node = this->leftRotate(node);
						node = node->right;
					}

					nodeCount = nodeCount >> 1;
				}

				return newNode;
			}

			/*!
			* \brief	
			*		\param[in]		node		The root node of the tree
			*		\param[in]		nodeCount	The number of nodes
			*
			*		\return			Return a pointer to the node after treatment
			*/
			Node<T>* leftBalanceVine(Node<T>* node, size_t nodeCount){
				size_t times = static_cast<size_t>(log2(static_cast<double>(nodeCount)));
				Node<T>* newNode = node;

				for(size_t i{0}; i < times; i++){
					newNode = this->rightRotate(newNode);
					node = newNode->left;

					for(size_t j{0}; j < (nodeCount/2 - 1); j++){
						node = this->rightRotate(node);
						node = node->left;
					}

					nodeCount = nodeCount >> 1;
				}

				return newNode;
			}

			/*!
			* \brief	
			*		\param[in]		tree		The root node of the tree
			*
			*		\return			Return a pointer to the node after treatment
			*/
			Node<T>* createRightVine(Node<T>* node){
				while(node->left != nullptr){
					node = this->rightRotate(node);
				}

				if(node->right != nullptr){
					node->right = this->createRightVine(node->right);
				}

				return node;
			}

			/*!
			* \brief	
			*		\param[in]		tree		The root node of the tree
			*
			*		\return			Return a pointer to the node after treatment
			*/
			Node<T>* createLeftVine(Node<T>* node){
				while(node->right != nullptr){
					node = this->leftRotate(node);
				}

				if(node->left != nullptr){
					node->left = this->createLeftVine(node->left);
				}

				return node;
			}

			/*!
			* \brief	Balance right the tree
			*		\param[in]		root		The root node of the tree
			*
			*		\return			Return a pointer to the node after treatment
			*/
			void rightBalance(){
				auto node = this->createRightVine(_root);

				_root = this->rightBalanceVine(node, this->getRightCount(node));
			}

			/*!
			* \brief	Balance left the tree
			*		\param[in]		root		The root node of the tree
			*
			*		\return			Return a pointer to the node after treatment
			*/
			void leftBalance(){
				auto node = this->createLeftVine(_root);

				_root = this->leftBalanceVine(node, this->getLeftCount(node));
			}

			/*!
			* \brief	Rotate the branch to the left
			*		\param[in]		node		The node to treat
			*
			*		\return			void
			*/
			Node<T>* leftRotate(Node<T>* node){
				if(node->right != nullptr){
					auto right = node->right;

					node->right = right->right;

					right->right = right->left;
					right->left = node->left;

					node->left = right;

					this->copier(node, right);
				}

				return node;
			}

			/*!
			* \brief	Rotate the branch to the right
			*		\param[in]		node		The node to treat
			*
			*		\return			void
			*/
			Node<T>* rightRotate(Node<T>* node){
				if(node->left != nullptr){
					auto left = node->left;

					node->left = left->left;

					left->left = left->right;
					left->right = node->right;

					node->right = left;

					this->copier(node, left);
				}

				return node;
			}

			/*!
			* \brief	Read the tree from left then root to right
			*		\param[in]		node		The root node of the tree
			*		\param[in]		func		The function to do something on each node
			*		\param[in]		index		The index to let know the number of GRD call
			*
			*		\return			void
			*/
			void GRD(Node<T>* node, void(*func)(Node<T>*, long int), long int index = -1){
				if(node != nullptr){
					if(index >= 0){
						GRD(node->left, func, index+1);
					} else {
						GRD(node->left, func, index);
					}

					func(node, index);

					if(index >= 0){
						GRD(node->right, func, index+1);
					} else {
						GRD(node->right, func, index);
					}
				}
			}

			/*!
			* \brief	Create a child for the tree
			*		\param[in]		values		The value for the child
			*		\param[in]		weight		The weight for the child
			*
			*		\return			Return a pointer to the node after treatment
			*/
			Node<T>* createChild(T values, NodeWeight weight){
				Node<T>* child = new Node<T>;

				child->values = values;
				child->weight = weight;
				child->initialized = true;

				return child;
			}

			/*!
			* \brief	Return the height of the tree
			*		\param[in]		root		The root node of the tree
			*
			*		\return			Return the height of the tree
			*/
			size_t height(Node<T>* node){
				if(node == nullptr){
					return 0;
				}

				int heightL = this->height(node->left);
				int heightR = this->height(node->right);

				return (heightL > heightR)?heightL+1:heightR+1;
			}

			/*! \brief	Set to nullptr all the functions pointer */
			void envoid(){
				deleter = nullptr;
				comparator = nullptr;
				copier = nullptr;
			}

		private:
			/*!
			* \brief	A function to print the node value in cout stream
			*		\param[in]		node		The root node of the tree
			*		\param[in]		index		The index to know how much point to print before the node value
			*
			*		\return			void
			*/
			static void printNode(Node<T>* node, long int index = -1){
				for(long int i{0}; i < index; ++i){
					std::cout << " ";
				}

				std::cout << node->weight << " -> '" << node->values << "'" << std::endl;
			}

			/*!
			* \brief	Copy datas from a node to another
			*		\param[in]		nodeSource		The node to get the datas
			*		\param[in]		nodeCopy		The node where to copy the datas
			*
			*		\return			void
			*/
			static void copyData(Node<T>* nodeSource, Node<T>* nodeCopy){
				T values = nodeSource->values;
				NodeWeight weight = nodeSource->weight;

				nodeSource->values = nodeCopy->values;
				nodeSource->weight = nodeCopy->weight;

				nodeCopy->values = values;
				nodeCopy->weight = weight;
			}

			/*!
			* \brief	A void deleter function
			*		\param[in]		node			The node to treat
			*
			*		\return			void
			*/
			static void treeDeleter(Node<T>*){}

		private:
			Node<T>* _root;

			TREE_DIRECTION (*comparator)(std::pair<T, NodeWeight>, std::pair<T, NodeWeight>);
			void (*deleter)(Node<T>*);
			void (*copier)(Node<T>*, Node<T>*);
	};
}

#endif //HEADER_CPP_TREE
