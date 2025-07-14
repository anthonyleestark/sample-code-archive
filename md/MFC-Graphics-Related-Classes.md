MFC offers **2 categories of graphics-related classes**:

---

### 🖌️ 1) **Device Context (CDC) Classes** – wrappers around an **HDC** (device context):

* **CDC** *(base class)*

  * **CPaintDC** – for use in `OnPaint()` (calls `BeginPaint`/`EndPaint`)
  * **CClientDC** – for custom client-area painting (calls `GetDC`/`ReleaseDC`)
  * **CWindowDC** – for painting entire windows (client + non‑client areas)
  * **CMetaFileDC** – for drawing to metafiles ([codeguru.com][1])

So there are **4 derived CDC classes**.

---

### 🎨 2) **GDI Object Classes** – derived from **CGdiObject**:

* **CGdiObject** *(abstract base)*

  * **CPen**
  * **CBrush**
  * **CBitmap**
  * **CFont**
  * **CPalette**
  * **CRgn** ([codeguru.com][1])

That's **6 GDI object classes** total.

---

### 📊 Summary Table

| Category               | Class Hierarchy                                           | Count |
| ---------------------- | --------------------------------------------------------- | :---: |
| **CDC Classes**        | CDC → CPaintDC, CClientDC, CWindowDC, CMetaFileDC         |   4   |
| **GDI Object Classes** | CGdiObject → CPen, CBrush, CBitmap, CFont, CPalette, CRgn |   6   |

---

### 🌳 Hierarchical View

```
CObject
└─ CGdiObject
   ├─ CPen
   ├─ CBrush
   ├─ CBitmap
   ├─ CFont
   ├─ CPalette
   └─ CRgn

CObject
└─ CDC
   ├─ CPaintDC
   ├─ CClientDC
   ├─ CWindowDC
   └─ CMetaFileDC
```

---

### 🔁 Total

* **4** CDC-derived classes
* **6** GDI object classes
* **10** total graphics classes in these two trees

---
