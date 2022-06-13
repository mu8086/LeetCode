#define NONE  -1

typedef struct _Node {
    struct _Node *colleague;
    struct _Node *firstEmployee;
    int informTime;
} Node;

int getNeededTime(Node *manager) {
    int neededTime = 0;

    if (manager->firstEmployee != NULL) {
        neededTime = getNeededTime(manager->firstEmployee);

        int colleague_neededTime;
        for (Node *colleague = manager->firstEmployee->colleague; colleague != NULL; colleague = colleague->colleague) {
            colleague_neededTime = getNeededTime(colleague);
            neededTime = (neededTime > colleague_neededTime) ? neededTime : colleague_neededTime;
        }
    }

    neededTime += manager->informTime;

    return neededTime;
}

int numOfMinutes(int n, int headID, int* manager, int managerSize, int* informTime, int informTimeSize){
    int i, myBoss;

    Node *managers = (Node *) malloc(sizeof(Node) * n);
    memset(managers, 0, sizeof(Node) * n);

    for (i = 0; i < n; ++i) {
        managers[i].informTime = informTime[i];
        
        myBoss = manager[i];
        if (myBoss == NONE) {
            continue;
        }
        
        if (managers[myBoss].firstEmployee == NULL) {
            managers[myBoss].firstEmployee = &managers[i];
        } else {
            managers[i].colleague = managers[myBoss].firstEmployee->colleague;
            managers[myBoss].firstEmployee->colleague = &managers[i];
        }
    }
    
    int neededTime = getNeededTime(&managers[headID]);
    free(managers);
    return neededTime;
}
