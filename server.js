const express = require('express');
const app = express();
const port = 3000;

app.use(express.json());

let energyUsage = 0;

app.post('/api/energy', (req, res) => {
    energyUsage = req.body.energyUsage;
    res.sendStatus(200);
});

app.get('/api/energy', (req, res) => {
    res.json({ energyUsage: energyUsage });
});

app.listen(port, () => {
    console.log(`Server running at http://localhost:${port}`);
});
