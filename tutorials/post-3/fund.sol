contract Fund {
    bool isOpen;
    address owner;

    constructor() public { owner = msg.sender; }

    function claim() public {
        owner = msg.sender;
    }

    function open() public {
        require(msg.sender == owner);
        isOpen = true;
    }

    function close() public {
        require(msg.sender == owner);
        isOpen = false;
    }

    function deposit() public payable { require(isOpen); }
}

contract Manager {
    Fund fund;

    constructor() public { fund = new Fund(); }

    function openFund() public { fund.open(); }
}
