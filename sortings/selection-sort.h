namespace SelectionSort
{
	template<typename T>
	void selectionSort(Node<T>**);

	template<typename T>
	void optimizedSelectionSort(Node<T>**);
	
	template<typename T>
	void selectionSort(Node<T>** head) {
		if (*head == nullptr) {
			cout << "Lista vazia" << endl;
			return;
		}

		Node<T>* outerLoop = nullptr;
		Node<T>* innerLoop = nullptr;

		for (outerLoop = *head; outerLoop != nullptr; outerLoop = outerLoop->ptrNext) {
			for (innerLoop = outerLoop; innerLoop != nullptr; innerLoop = innerLoop->ptrNext) {
				if (innerLoop->iPayload < outerLoop->iPayload) {
					swapNodesValues(innerLoop->iPayload, outerLoop->iPayload);
				}
			}
		}
	}

	template<typename T>
	void optimizedSelectionSort(Node<T>** head) {
		Node<T>* minNode;
		Node<T>* outerLoop;
		Node<T>* innerLoop;

		for (outerLoop = *head; outerLoop != nullptr; outerLoop = outerLoop->ptrNext) {
			minNode = outerLoop;

			for (innerLoop = outerLoop; innerLoop != nullptr; innerLoop = innerLoop->ptrNext) {
				if (innerLoop->iPayload < minNode->iPayload) {
					minNode = innerLoop;
				}
			}

			swapNodesValues(outerLoop->iPayload, minNode->iPayload);
		}
	}
}