contract Crowdsale {
    uint raised;
    uint goal;
    uint deadline;

    bool finished; // Instrumented.
    bool canceled; // Instrumented.

    constructor(uint _goal) public {
        goal = _goal;
        deadline = now + 365 days;
    }

    function invest() public payable {
        require(now <= deadline);
        raised += msg.value;
    }

    function finish() public {
        require(address(this).balance >= goal);
        finished = true; // Instrumented.
    }

    function cancel() public {
        require(address(this).balance < goal && now > deadline);
        canceled = true; // Instrumented.
    }

    function repOK() public view {
        assert(!(finished && canceled)); // Instrumented.
    }
}

