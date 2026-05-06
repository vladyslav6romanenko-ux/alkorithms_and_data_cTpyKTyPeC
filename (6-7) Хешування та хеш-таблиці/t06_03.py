_size = 100003
_keys = None
_values = None

def _custom_hash(s):
    h = 0
    for char in s:
        h = (h * 31 + ord(char)) % _size
    return h

def init():
    global _keys, _values
    _keys = [None] * _size
    _values = [None] * _size

def addBook(author, title):
    global _keys, _values
    idx = _custom_hash(author)
    start_idx = idx

    while _keys[idx] is not None:
        if _keys[idx] == author:
            for b in _values[idx]:
                if b == title:
                    return
            _values[idx].append(title)
            _values[idx].sort()
            return
        idx = (idx + 1) % _size
        if idx == start_idx:
            return

    _keys[idx] = author
    _values[idx] = [title]

def find(author, title):
    idx = _custom_hash(author)
    start_idx = idx

    while _keys[idx] is not None:
        if _keys[idx] == author:
            # Шукаємо книгу в списку автора
            for b in _values[idx]:
                if b == title:
                    return True
            return False
        idx = (idx + 1) % _size
        if idx == start_idx:
            break
            
    return False

def delete(author, title):
    idx = _custom_hash(author)
    start_idx = idx

    while _keys[idx] is not None:
        if _keys[idx] == author:

            for i in range(len(_values[idx])):
                if _values[idx][i] == title:
                    _values[idx].pop(i)
                    return
            return
        idx = (idx + 1) % _size
        if idx == start_idx:
            break

def findByAuthor(author):
    idx = _custom_hash(author)
    start_idx = idx

    while _keys[idx] is not None:
        if _keys[idx] == author:
            return _values[idx]
        idx = (idx + 1) % _size
        if idx == start_idx:
            break
            
    return []
