namespace SelectionSort
{
	void selectionSort(Node**);
	void optimizedSelectionSort(Node**);
	
	void selectionSort(Node** head){
		if(*head == nullptr){
			cout << "Lista vazia" << endl;
			
			return;
		}
		
		bool bSwapped;
		Node* outerLoop = nullptr;
		Node* innerLoop = nullptr;

		for (outerLoop = *head; outerLoop != nullptr; outerLoop = outerLoop->ptrNext){
			for (innerLoop = outerLoop; innerLoop != nullptr; innerLoop = innerLoop->ptrNext){
				if(innerLoop->iPayload < outerLoop->iPayload){
					swapNodesValues(innerLoop->iPayload, outerLoop->iPayload);
				}
			}
		}
	}

	void optimizedSelectionSort(Node** head){
		Node* minNode;
		Node* outerLoop;
		Node* innerLoop;

		for (outerLoop = *head; outerLoop != nullptr; outerLoop = outerLoop->ptrNext){
			minNode = outerLoop;

			for (innerLoop = outerLoop; innerLoop != nullptr; innerLoop = innerLoop->ptrNext){
				if(innerLoop->iPayload < outerLoop->iPayload){
					minNode = innerLoop;
				}
			}

			swapNodesValues(outerLoop->iPayload, minNode->iPayload);
		}
	}
}