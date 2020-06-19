contract Auction {
    bool isOpen;
    address owner;

    uint256 maxBid;

    mapping(address => uint) bids;

    constructor() public { owner = msg.sender; }

    // Access controls.
    modifier ownerOnly() { require(owner == msg.sender); _; }
    function releaseTo(address _new) public ownerOnly { owner = _new; }
    function open() public ownerOnly { isOpen = true; }
    function close() public ownerOnly { isOpen = false; }

    // Place a bid.
    function deposit() public payable {
        uint256 bid = bids[msg.sender] + msg.value;
        require(isOpen);
        require(bid > maxBid);
        bids[msg.sender] = bid;
        maxBid = bid;
    }

    // Withdraw a losing bid.
    function withdraw() public payable {
        uint256 bid = bids[msg.sender];
        require(isOpen);
        require(bid < maxBid);
        bids[msg.sender] = 0;
        msg.sender.transfer(bid);
    }
}

contract Manager {
    Auction auction;

    constructor() public { auction = new Auction(); }

    function openAuction() public { auction.open(); }
}

