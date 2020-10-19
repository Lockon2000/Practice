from typing import Any


class Entry(object):
    def __init__(self, key: str, value=None):
        self.key = key
        self.value = value

    @property
    def hash(self) -> int:
        """return entry's hash"""
        return len(self.key)

    def __repr__(self):
        return f"<Entry hash={self.hash}, key={self.key}, value={self.value}>"

    def __str__(self):
        return str(self.value)

    def __eq__(self, other: object) -> bool:
        """Check equation with other entries, e.g dict['a'] == dict['b']"""
        if not isinstance(other, Entry):
            return NotImplemented
        return self.value == other.value

    def compare_hash(self, other: object) -> bool:
        """compare keys and hashes with different entry"""
        if not isinstance(other, Entry):
            return NotImplemented
        return self.key == other.key and self.hash == other.hash

class CustomDict(object):
    def __init__(self, size=10):
        self.entries = [None for _ in range(size * 2)]
        self.size = size
        self.actual_size = size * 2
        self.filled_entries = 0

    def __getitem__(self, key: str) -> Entry:
        """subscript method - object[key]
        use hashing function to find the index"""
        entry = Entry(key)
        index = entry.hash % self.actual_size
        found = self.entries[index]
        while found and not entry.compare_hash(found):
            index = (index + 1) % self.actual_size
            found = self.entries[index]
        if found == None:
            raise KeyError

        # both keys and hashes match
        return found

    def __setitem__(self, key: str, value: Any) -> int:
        """allow insertion of items with object[key] = value"""
        if self.filled_entries == self.size:
            # no more room
            raise KeyError
        entry = Entry(key, value)
        index = entry.hash % self.actual_size
        existing_entry = self.entries[index]
        while existing_entry and not entry.compare_hash(existing_entry):
            # don't overlap existing values
            index = (index + 1) % self.actual_size
            existing_entry = self.entries[index]
        self.entries[index] = entry
        self.filled_entries += 1
        return index
