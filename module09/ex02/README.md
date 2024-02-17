#Merge-isertion sort (ford-johnson algorithm).
### First of all what is Merge-insertion ?
Merge-insertion sort (fors-johnson algorightm) is in-plase sorting algorithm designed to perform as few comparisons as possible to sort a collection.

### first step:
let's say we have this sequence: 
    
    566 880 712 875 760 769 43 274 111 695 87 283 540 60 361 637 623 417 668 92 877 661 400 222 569 865 155 493 442 790 186 30 364 423 468 717 137 518 437 546 676 413 808 391 210 644 832 304 703 887 205

Remove the last element and save it into lastElement variable, if the size of element % 2 don't equal to 0. we have sequence of size 51, so we have to remove the last element (last element here is 205), and save it into lastElement, so lastElement = 205.

### second step: 
split this sequence into pairs and sort these pairs by the large element by recursively sort.
```   void   sortPairs(std::vector<std::vector<int> > vector, int pairsNum); ```
this function (sortPairs) will be responsible for sort these pairs by recursively, sortPairs will return nothing, and accept two parameter here, the first one is vector contains the sequence above, and the last parameter contains how many of element in each pair. And this function will handle two cases: 
###### first case:
this case we will collect pairNum into each pair (function start with pairNum = 1 and each time pairNum * 2).
And this case will be stop when pairNum equal to 51 (we all know size of the sequence is 51) and start the second case.
###### second case:
simply this case will start when finish the first case, so when pairNum = 51, and will stop when pairNum = 1,

we can say the first case is recursivly of the sortPairs function, and second case is reverse recursivly.

### third step: 

