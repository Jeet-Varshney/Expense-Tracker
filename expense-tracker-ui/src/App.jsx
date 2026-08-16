import './App.css'

function App() {

  return (
    <div className='app'>
      <aside>
        <h2>Expense Tracker</h2>
        <nav>
          <a href="/dashboard">Dashboard</a>
          <a href="/expenses">Expenses</a>
          <a href="/categories">Categories</a>
          <a href="/settings">Settings</a>
        </nav>
      </aside>
      <main>

        <h1>Dashboard</h1>
        <p>Welcome Back!</p>

        <div className="summary-cards">
          <div className="card">
            <h3>Total spends</h3>
            <p>Rs.12,450</p>
          </div>

          <div className="card">
            <h3>This Month</h3>
            <p>Rs.2,450</p>
          </div>

          <div className="card">
            <h3>Transactions</h3>
            <p>24</p>
          </div>
        </div>

        <section>
          <h2>Recent Transactions</h2>
          <div className="transactions">
            <div className="transaction">
              <span>Food</span>
              <span>₹250</span>
              <span>17-08-2026</span>
            </div>

            <div className="transaction">
              <span>Travel</span>
              <span>₹500</span>
              <span>15-08-2026</span>
            </div>

            <div className="transaction">
              <span>Shopping</span>
              <span>₹420</span>
              <span>12-08-2026</span>
            </div>
          </div>
        </section>
        
      </main>
    </div>
  )
}

export default App
