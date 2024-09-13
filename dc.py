
import inspect
from pprint import pprint
from dataclasses import dataclass, astuple, asdict

@dataclass(frozen=True, order=True)
class Comment:
    id: int
    text: str


def main():
    comment = Comment(1, "I just subbed")
    print(comment)
    print(astuple(comment))
    print(asdict(comment))
    pprint(inspect.getmembers(Comment, inspect.isfunction))


if __name__ == "__main__":
    main()